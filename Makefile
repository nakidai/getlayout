PREFIX ?= /usr

all: getlayout

install: getlayout
	install -m 555 getlayout ${PREFIX}/bin/getlayout

clean:
	rm -f getlayout

getlayout:
	cc -lX11 -lxkbfile getlayout.c -o getlayout

.PHONY: all install clean
