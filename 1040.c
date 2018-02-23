#include <stdio.h>
#define SIZE 100000

unsigned int countInArr(char in[], char ch);

int main(){
    char in[SIZE];
    int unsigned numT, numP, cou = 0;
    const int unsigned mod = 1000000007;
    scanf("%s", in);
    numP = 0;
    numT = countInArr(in, 'T');
    for(int i = 0; in[i] != '\0'; i++){
        cou = cou % mod;
        if(in[i] == 'A'){
            cou = cou + numT * numP;
        } else {
            if(in[i] == 'P')
                numP++;
            else
                numT--;
        }
    }
    cou = cou % mod;
    printf("%d", cou);
    return 0;
}

unsigned int countInArr(char in[], char ch){
    int unsigned n = 0;
    for(int i = 0; in[i] != '\0'; i++)
        if(in[i] == ch)
            n++;
    return n;
}

/*  用了锁定 A 的方法后还用下面的方法计算 P/T, 我真是傻子
        for(int m = i; in[m] != '\0'; m++){
            if(in[m] != 'T')
                continue;
            else
                numT++;
        }
        for(int n = 0; n < i; n++){
            if(in[n] != 'P')
                continue;
            else
                numP++;
        }
*/
