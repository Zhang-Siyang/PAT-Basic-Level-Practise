#include <stdio.h>
#define NOS 100001

int main(){
    int maxSc = 0, maxSco = 0, sco, pForSc, i; 
    /* maxSc ~ 学校编号的最大值, maxSco ~ 评分最大值,
     sco ~ 评分保存地, pForSc ~ 指向学校数组的'指针' */
    int scCo[NOS] = {0};
    /* scCo ~ 存储学校总分 */
    scanf("%d", &i);
    for(;i > 0; i--){
        scanf("%d%d", &pForSc, &sco);
        if(pForSc > maxSc)
            maxSc = pForSc;
        scCo[pForSc] += sco;
    }
    for(i = 0; i < NOS; i++){
        if(scCo[i] > maxSco){
            pForSc = i;
            maxSco = scCo[i];
        }
    }
    printf("%d %d", pForSc, maxSco);
    return 0;
}
