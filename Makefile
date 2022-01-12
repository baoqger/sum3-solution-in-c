CFLAGS =-Wall -Werror

sum3: sum3.c
	cc sum3.c -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm 