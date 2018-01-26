FLAGS = -std=c99 -Wall
SOURCES = FileIO.c
OBJECTS = FileIO.o
EXEBIN = fileio

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

