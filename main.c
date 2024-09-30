#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int try_parse(char* number, long long* result) {
    char* end = 0;
    errno = 0;
    *result = strtoll(number, &end, 10);
    return errno == 0 && end == number + strlen(number);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("FEWARGS\n");
        return 1;
    }
    
    long long x, y;
    if(!try_parse(argv[1], &x) || !try_parse(argv[2], &y)) {
        printf("INVALIDINPUT\n");
        return 1;
    }

    printf("%lld\n", x + y);
    return 0;
}
