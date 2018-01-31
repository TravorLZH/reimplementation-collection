TARGET=demo
SOURCES=$(wildcard *.c)
OBJ=${SOURCES:.c=.o}

all:	$(TARGET)

$(TARGET):	$(OBJ)
	gcc -g -o $@ $^

%.o:	%.c
	gcc -c $^ -o $@
clean:
	rm -rf $(TARGET) *.o

