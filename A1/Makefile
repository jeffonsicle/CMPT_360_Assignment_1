CC:= gcc-13
CFLAGS:=-std=c11-Wall-Wextra-pedantic-O2-g
LDFLAGS:=

#Valgrind
VALGRIND?=valgrind
VGFLAGS?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak
kinds=all --error-exitcode=1
.PHONY: all clean check valgrind vg

all: testprog

testprog: testprog.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

testprog.o:testprog.c
	$(CC) $(CFLAGS) -c $<

check: testprog
	@echo 'Bob123' | ./testprog
	@echo 'a!' | ./testprog
	@echo 'Admin42' | ./testprog
	@echo 'rootuser' | ./testprog
	@echo '_99' | ./testprog

#Run sample input under Valgrind; fails build on leaks/errors
valgrind: testprog
	$(VALGRIND) $(VGFLAGS) ./testprog < tests/input.txt

vg: valgrind

clean:
	rm -f testprog testprog.o