#include <stdio.h>

int find(char in[], char tar);
int strcpy_se(char str1[], char str2[], int st, int end);
int putFace(int a[], char * h[], char * e[], char * m[]);
int countInStr(char str[], char ch);
int putToArr(char in[], char * b[]);

int main(){
    char emoji[3][10][9];
    char in[200];
    int face[5];
    for(int i = 0; i < 3; i++){
        scanf("%s", in);
        putToArr(in, emoji[i]);
        printf("#Finish %d Times Read.#\n", i);
    }
    int f;
    scanf("%d", &f);
    for(int i = 0; i < f; i++){
        for(int i = 0; i < 5; i++){
            scanf("%d", &face[i]);
        }
        putFace(face, emoji[0], emoji[1], emoji[2]);
    }
    return 0;
}

int find(char in[], char tar){
    int i;
    for(i = 0; in[i] != '\0'; i++){
        if(in[i] == tar)
            break;
    }
    if(in[i] == '\0')
        return -1;
    else
        return i;
}

int strcpy_se(char str1[], char str2[], int st, int end){
    printf("#Start Save Emoji, St:%d End:%d From:%p To:%p#\n", st, end, str2, str1);
    int i;
    for(i = 0; end >= (st + i); i++){
        printf("#I will set str1(%p)[%d] to '%c'#\n", str1, i, str2[st + i]);
        str1[i] = str2[st + i];
    }
    str1[i] = '\0';
    printf("#Save Finished, The char of copyed has %d#\n", i);
    return i;
}

int putFace(int a[], char * h[], char * e[], char * m[]){
    int flag;
    if( *(h[a[0]]) == '\0' || *(e[a[1]]) == '\0' || *(m[a[2]]) == '\0' || *(e[a[3]]) == '\0' || *(h[a[4]]) == '\0'){
        printf("Are you kidding me? @\\/@");
        flag = -1;
    } else {
        printf("%s%s%s%s%s", h[a[0]], e[a[1]], m[a[2]], e[a[3]], h[a[4]]);
        flag = 0;
    }
    putchar('\n');
    return flag;
}

int countInStr(char str[], char ch){
    printf("#In int conutInStr.#\n");
    int n = 0;
    for(int i = 0; str[i] != '\0'; i++){
        printf("#Search '%c' in String(%p). Now, i = %d#\n", ch, str, i);
        if(str[i] == ch)
            n++;
    }
    printf("#Finish countInStr, return %d#\n", n);
    return n;
}

int putToArr(char in[], char * b[]){
    printf("#In int putToArr.#\n");
    int st = 0, end = 0, n = countInStr(in, '[');
    for(int i = 0; i < n; i++){
        st = find(in, '[');
        end = find(in, ']');
        strcpy_se(b[n], in, st + 1, end - 1);
        in[st] = ' ';
        in[end] = ' ';
    }
    return n;
}
