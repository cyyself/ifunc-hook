#include <stdio.h>

void dummy();

__attribute__ ((ifunc ("resolve_hello")))
void hello();

void hello_impl() {
    printf("hello\n");
}

void (*resolve_hello())() {
    return hello_impl;
}

int main(int argc) {
    hello();
    if (argc >= 2) dummy();
    return 0;
}
