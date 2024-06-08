#include <stdio.h>

void dummy_impl() {
    printf("dummy\n");
}

__attribute__ ((ifunc ("resolve_dummy")))
void dummy();

void hack() {
    printf("hacked\n");
    /*
      Here .GOT is mapped to be writable.
      So there is a chance to hijack .GOT.

      TODO: Implement the hijack `hello` symbol here.
     */
}

void (*resolve_dummy())() {
    hack();
    return dummy_impl;
}
