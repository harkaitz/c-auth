## -- manpages --
install: install-man
install-man: ./doc/sys_authorization.3.md 
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/sys_authorization.3  $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-auth
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-auth
## -- license --
