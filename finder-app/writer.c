/*
3. Write a C application “writer” (finder-app/writer.c)  which can be used as an alternative to the “writer.sh” test script created in assignment1 and using File IO as described in LSP chapter 2.  See the Assignment 1 requirements for the writer.sh test script and these additional instructions:

    One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

    Setup syslog logging for your utility using the LOG_USER facility.

    Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

    Use the syslog capability to log any unexpected errors with LOG_ERR level.
*/

/*
Date: 02/03/24
Author: AALogisz
*/

#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define WRITEFILE 1
#define WRITESTR  2

#define LOG_OPT (LOG_CONS | LOG_PID)

//Args: 
//1: writefile (full path to file) 
//2: writestr (string to be written into file)

//Errors:
//Incorrect num args passed.
//Directory not found. 

int main(int argc, char* argv[])
{
	int ret = 0;

	char* writefile = argv[WRITEFILE];
	char* writestr = argv[WRITESTR];
	int file = -1;
	size_t writestr_size = 0;
	
	//Writing <> to <>
	char mesg[] = "Writing ";
	
	openlog(NULL, LOG_OPT, LOG_USER);

	strcat(mesg, writestr);
	strcat(mesg, " to ");
	strcat(mesg, writefile);

	//Error
	//If number of arguments is not equal to 3. (First arg is process)
	if(argc < 3)
	{
		syslog(LOG_ERR, "Too few arguments");
		ret = 1;
	}
	else
	{
		file = open(writefile, O_WRONLY);
		
		
		if(file < 0)
		{
			syslog(LOG_ERR, "File access error");
			ret = 1;
		}
		
		writestr_size = strlen(writestr);
		
		syslog(LOG_DEBUG, mesg);
		
		write(file, writestr, writestr_size);
		
		close(file);
	}
	
	closelog();
	
	return ret;
}
