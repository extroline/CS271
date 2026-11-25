CC = gcc
CFLAGS = -Wall -I.
LDFLAGS = 
OBJFILES = main.o parser.o symtable.o error.o
DEPS = hack.h parser.h symtable.h error.h
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~