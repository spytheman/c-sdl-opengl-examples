CFLAGS=-g
LDFLAGS=-lSDL -lGL

all: triangle

triangle:

.PHONY: clean all

clean:
	rm -rf triangle