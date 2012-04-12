JAVAC:=javac
CC:=gcc
OPTS:=-pedantic -Wall -Wextra -O3

.PHONY: clean

all: Main.class main

Main.class: Main.java
	$(JAVAC) $^
	
main: main.c
	$(CC) $(OPTS) -o $@ $^

clean:
	-rm -rf Main.class main

