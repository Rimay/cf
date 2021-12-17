#include <cstdio>
#include <cstdlib>
#include "sys/mman.h"
#include "sys/wait.h"
#include <unistd.h>
#include <fcntl.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#define CONTENT "hello"
char buf[256] = {0};

int main(void)
{
    int fd = open("/dev/zero", O_RDWR, 0);
    void *addr = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
    printf("fd: %d\naddr:%x\n", fd, *(int *)addr);
    // int len = read(fd, buf, 5);
    // int len = write(fd, CONTENT, 5);

    int pid = fork();
    if (pid == 0) {
        *(int *)addr = 2021;
        printf("process %d val = %d\n", getpid(), *(int *)addr);
        munmap(addr, 4);
        close(fd);
        exit(0);
    }

    wait(NULL);
    printf("process %d val = %d\n", getpid(), *(int *)addr);
    munmap(addr, 4);
    close(fd);
    return 0;
}