CC := gcc
CFLAGS := -g -Wl,-z,relro,-z,now

hello: hello.c libmalicious.so
	$(CC) $(CFLAGS) hello.c -L. -lmalicious -o $@

libmalicious.so: malicious.c
	$(CC) $(CFLAGS) $< -fPIC -shared -o $@

.PHONY: clean

clean:
	rm -f hello libmalicious.so
