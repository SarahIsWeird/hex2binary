INSTALL_PATH := /usr/local/bin

CC := gcc
CFLAGS := -std=c89

SRC := main.c
TARGET := h2b

.PHONY: clean

all:
	@$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

clean:
	@rm ./$(TARGET)

install: all
	@cp ./$(TARGET) $(INSTALL_PATH)/$(TARGET)

uninstall:
	@rm $(INSTALL_PATH)/$(TARGET)
