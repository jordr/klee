// RUN: %clang %s -emit-llvm -g -c -I "%libc_include" -o %t1.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --libc=uclibc --exit-on-error %t1.bc > %t1.out 2>&1
// RUN: FileCheck %s -input-file=%t1.out
// RUN: test ! -f %t.klee-out/test000001.exec.err

// CHECK-NOT: has inline asm
// CHECK-NOT: inline assembly is unsupported

#include <sys/select.h>

int main() {
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return 0;
}
