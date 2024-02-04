#!/bin/bash

#$1 writefile
#$2 writestr


if [ ! $# -eq 2 ]
then

	exit 1

elif [ -z "$1" ]
then
	
	exit 1
	
else

	echo "$2" > $1
	
	if [ ! -e $1 ]
	then
	
		exit 1
	
	fi
fi
