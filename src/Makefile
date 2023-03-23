SHELL = /bin/sh

IDIR = ../include
ODIR = obj

CC = gcc
CFLAGS = -I $(IDIR)

_DEPS = riskxvii.h token.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_MAIN_OBJ =  riskxvii.o
_PARSE_OBJ = file.o flag.o notify.o
_DEP_OBJ = alias.o label.o macro.o token.o offset.o 
_ASM_OBJ = assemble.o operand.o opcode.o
_OBJ = $(_MAIN_OBJ) $(_PARSE_OBJ) $(_DEP_OBJ) $(_ASM_OBJ)
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

riskxvii: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean install uninstall

clean:
	rm -f $(ODIR)/*.o && rm -f riskxvii

install:
	cp riskxvii /usr/local/bin

uninstall:
	rm -f /usr/local/bin/riskxvii
