#include <stdio.h>

int main(){
    char in[1000] = {'\0'}, ch, ttl = 0;
    int i = 0;
    while( (ch = getchar()) >= '0' && ch <= '9'){
        in[i] = ch;
        i++;
    }
    in[i] = '\0';
    s(in, ttl);
    return 0;
}

void s(char in[], int ttl){
    if(ttl >= 10){
        printf("Not found in 10 iterations.");
    } else if( isP(in) ){
        printf("%s is a palindromic number.", in);
    } else {
        getP(in, ++ttl);
    }
    return;
}

getP(char in[], int ttl){
    printf("%s + ", in);
    int len = getLength(in);
    int i = getLength(in) - 1;
    for(; i >= 0; i--){
        putchar(in[i]);
    }
    printf(" = ");
    char * p;
    p = (char *)malloc((len) * sizeof(char));
    for(int i = 0; len > 0; len--, i++){
        p[i] = in[len];
    }
    
}

int isP(char in[]){
    int len = getLength(in);
    len--;
    for(int i = 0; i < len;){
        if(in[i] == in[len]){
            i++;
            len--;
        } else {
            break;
        }
    }
    if(i < len)
        return -1;
    else
        return 1;
}

int getLength(char in[]){
    int i = 0;
    while(in[i] != '\0')
        i++;
    return i;
}
