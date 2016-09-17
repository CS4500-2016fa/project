#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#define __NR_print_other 339
int main(int argc, char *argv[]) {
	printf(argv[1]);
	int pid = atoi(argv[1]);
	syscall(__NR_print_other, pid);
	return 0;
}

