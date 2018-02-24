#include <stdio.h>

#define INLEN 1000
#define LEN (INLEN+1)

int getLength(char in[]);

int main(){
    char in[LEN];
    int b, y = 0, inlen;
    scanf("%s %d", in, &b);
    inlen = getLength(in);
    for(int i = 0; i < inlen; i++){
        y = y * 10 + (in[i] - '0');
        if(i == 0)
            continue;
        printf("%d", (y / b));
        y = y % b;
    }
    printf(" %d", y);
    return 0;
}

int getLength(char in[]){
    int i = 0;
    while(in[i] != '\0')
        i++;
    return i;
}
