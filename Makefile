DESTDIR =
PREFIX  =/usr/local
HEADERS =sys/authorization.h

all:
install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/sys
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/sys
clean:

## -- manpages --
MAN_3=./doc/sys_authorization.3 
install: install-man3
install-man3: $(MAN_3)
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp $(MAN_3) $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-auth
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-auth
## -- license --
