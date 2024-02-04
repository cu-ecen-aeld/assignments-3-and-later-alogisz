CC=aarch64-none-linux-gnu-gcc
CROSS_COMPILE=aarch64-none-linux-gnu-
DIR=-I.
FLAGS=-g -Wall
SRCS=$(wildcard *.c)
OBJS=$(SRCS)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(DIR)
%: %.o
	
writer: $(OBJS)
	$(CC) -o $@ $< $(FLAGS) $(DIR)

clean:
	rm -f *.o writer


