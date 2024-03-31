CC = gcc
CFLAGS = -Wall -Wextra
TARGET = grocery_bill
SRC_MAIN = main.c
SRC_FUNCTIONS = functions.c
OBJ_FUNCTIONS = functions.o
HEADERS = functions.h

all: $(TARGET)

$(TARGET): $(OBJ_FUNCTIONS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_MAIN) $(OBJ_FUNCTIONS)

$(OBJ_FUNCTIONS): $(SRC_FUNCTIONS) $(HEADERS)
	$(CC) $(CFLAGS) -c -o $(OBJ_FUNCTIONS) $(SRC_FUNCTIONS)

clean:
	rm -f $(TARGET) $(OBJ_FUNCTIONS)
