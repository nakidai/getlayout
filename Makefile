PREFIX ?= /usr
LDLIBS = -lX11 -lxkbfile

all: getlayout

install: getlayout
	install -m 555 getlayout ${PREFIX}/bin/getlayout

clean:
	rm -f getlayout

.PHONY: all install clean
