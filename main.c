#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int getFileSize(int fd) {
    if(fd == -1) {
        return -1;
    }
    struct stat buf;
    fstat(fd, &buf);
    return buf.st_size;
}

void cat(char toOpen[]) {
    int fd = open(toOpen, O_RDONLY );
    if(fd == -1) {
        printf("Error occured while opening file.");
        return;
    }
    long bytesRead;
    int (*fileSize)(int) = &getFileSize;
    int fileBytes = (*fileSize)(fd);
    char buf[fileBytes];
    bytesRead = read(fd, &buf, fileBytes);
    printf("# of bytes read: %ld \n",bytesRead);

    long numWritten = write(STDOUT_FILENO, &buf, strlen(buf));
    if(numWritten == -1) {
        printf("Error occured while writing from buffer.");
        return;
    }
    close(fd);
}

int main(int argc , char *arv[]) {
    cat("/etc/fstab");
}
