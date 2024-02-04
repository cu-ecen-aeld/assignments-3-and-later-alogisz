#!/bin/bash

#$1 filesdir
#$2 searchstr


files=0
lines=0


if [ ! $# -eq 2 ]
then

	echo 1
	
elif [ ! -e $1 ]
then

	echo 1
	
else
	#Determine the number files with searchstr
	files=$(grep $2 $1 -l -R | wc -l)
	#Determine the number of lines with searchstr
	lines=$(grep $2 $1 -c -l -R | wc -l)

	echo "The number of files are ${files} and the number of matching lines are ${lines}"
fi
