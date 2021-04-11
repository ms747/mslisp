CS=src/builtins.c src/expr.c src/gc.c src/interpreter.c src/parser.c src/scope.c src/std.c src/tokenizer.c src/str.c
OBJS=builtins.o expr.o gc.o interpreter.o parser.o scope.o std.o tokenizer.o str.o
CFLAGS=-Wall -Werror
CC=gcc

.PHONY: all
all: libmslisp.a mslisp

$(OBJS): $(CS)
	$(CC) $(CFLAGS) -c $(CS)

libmslisp.a: $(OBJS)
	ar -crs libmslisp.a $(OBJS)

mslisp: libmslisp.a src/repl.c src/repl_runtime.c
	$(CC) $(CFLAGS) -o repl src/repl.c src/repl_runtime.c -L. -lmslisp
