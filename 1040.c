#include <stdio.h>
#define SIZE 100000

int main(){
    char in[SIZE];
    int unsigned numT, numP, cou = 0;
    const int unsigned mod = 1000000007;
    scanf("%s", in);
    for(int i = 0; in[i] != '\0'; i++){
        numT = numP = 0;
        cou = cou % mod;
        if(in[i] != 'A')
            continue;
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
        cou = cou + numT * numP;
    }
    cou = cou % mod;
    printf("%d", cou);
    return 0;
}
