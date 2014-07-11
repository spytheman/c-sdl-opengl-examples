CFLAGS=-Os -fomit-frame-pointer 
LDFLAGS=-lSDL -lGL

all: triangle

triangle:

.PHONY: clean all

clean:
	rm -rf triangle