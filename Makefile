SRCDIR=src/
BINDIR=bin/
DOCDIR=docs/
 
RM = rm -rf
CC = gcc -Wall
PROG = prog
 
SRC= $(wildcard $(SRCDIR)*.c)
OBJ= $(SRC:$(SRCDIR)%.c=$(BINDIR)%.o)
HEAD=$(SRC:.c=*.h)
 
all : $(PROG) 
 
$(PROG): $(OBJ)
	$(CC) $^ -o $@ -g -lm
 
$(BINDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $< -o $@ -g -lm
 
$(BINDIR)main.o: $(SRCDIR)main.c
	$(CC) -c $^ -o $@ -g -lm
 
run :
	./prog
 
.PHONY : doc
doc: 
	doxygen Doxyfile
 
.PHONY : clean
clean:
	@$(RM) $(PROG) $(BINDIR)*.o $(DOCDIR)html $(DOCDIR)latex
.PHONY : debug
 