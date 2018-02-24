/* 部分借鉴了 柳婼 在 https://www.liuchuo.net/archives/537 的文章, 特别感谢暂不具名人士的帮助*/
#include <stdio.h>

#define INLEN 1000  /* 输入大整数的最大长度 */
#define LEN (INLEN+1)   /* 要存储该数需消耗的字符数组长度 */

int getLength(char in[]);

int main(){
    char in[LEN];
    int b, y = 0, inlen;    /* b ~ 被除数 */
    scanf("%s %d", in, &b);
    inlen = getLength(in);

    if(inlen == 1){ /* 当 inlen 为 1 时, 不再适合下面的处理方式(与 continue 冲突) */
        printf("%d %d", (in[0] - '0') / b, (in[0] - '0') % b);
        return 0;
    }

    for(int i = 0; i < inlen; i++){
        y = y * 10 + (in[i] - '0');
        if(i == 0)
            continue;
        printf("%d", y / b);
        y = y % b;
    }
    printf(" %d", y);
    return 0;
}

int getLength(char in[]){   /* 求字符数组长度, 返回的是第一个 '\0' 前的字符个数*/
    int i = 0;
    while(in[i] != '\0')
        i++;
    return i;
}
