CC=gcc
#CC=aarch64-none-linux-gnu-gcc
DIR=-I.
FLAGS=-g -Wall
SRCS=$(wildcard *.c)
OBJS=$(SRCS)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS) $(DIR)
%: %.o
	
writer: $(OBJS)
	$(CC) -o $@ $< $(FLAGS) $(DIR)

clean:
	rm -f *.o writer


