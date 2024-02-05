CROSS_COMPILE=
CC=gcc
DIR=-I.
FLAGS=-g -Wall
SRCS=$(wildcard *.c)
OBJS=$(SRCS)

%.o: %.c
	$(CROSS_COMPILE)$(CC) -c -o $@ $< $(FLAGS) $(DIR)
%: %.o
	
writer: $(OBJS)
	$(CROSS_COMPILE)$(CC) -o $@ $< $(FLAGS) $(DIR)

clean:
	rm -f *.o writer
