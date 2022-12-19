### 解题思路
C语言题解， 处理字符串很麻烦

### 代码

```c
static char*** S;
static int SLen;

void helper(int n)
{
    if (n == 1) {
        return ;
    }
    for (int i = 0; i < n/2; i++) {
        S[SLen][i][0] = '(';
        strcat(S[SLen][i], S[SLen-1][i]);
        strcat(S[SLen][i], ",");
        strcat(S[SLen][i], S[SLen-1][n-1-i]);
        strcat(S[SLen][i], ")");
        //puts(S[SLen][i]);
    }
    //puts(S[SLen][0]);
    SLen++;
    helper(n/2);
}


char * findContestMatch(int n){
    S = (char***)malloc(13*sizeof(char**));
    SLen = 0;
    S[SLen] = (char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++) {
        S[SLen][i] = (char*)malloc(5*sizeof(char));
        memset(S[SLen][i], '\0', 5*sizeof(char));
    }
    char* tmp = (char*)malloc(5*sizeof(char));
    memset(tmp, '\0', 5*sizeof(char));
    for (int i = 1; i <= n; i++) {
        memset(tmp, '\0', 5*sizeof(char));
        sprintf(tmp, "%d", i);
        strcpy(S[SLen][i-1], tmp);
        //puts(S[SLen][i-1]);
    }
    free(tmp);
    SLen++;
    int SijSize = 5;
    for (int i = 1; i < 13; i++) {
        int SiSize = n / (int)pow(2, i);
        if (n == 0) {
            break;
        }
        S[i] = (char**)malloc(SiSize*sizeof(char*));
        SijSize = 2*(SijSize-1)+3+1;
        printf("%d ", SijSize);
        for (int j = 0; j < SiSize; j++) {
            S[i][j] = (char*)malloc(SijSize*sizeof(char));
            memset(S[i][j], '\0', SijSize*sizeof(char));
        }
    }
    helper(n);
    char* res = (char*)malloc(SijSize*sizeof(char));
    memset(res, '\0', SijSize*sizeof(char));
    strcpy(res, S[SLen-1][0]);
    for (int i = 0; i < 13; i++) {
        int SiSize = n / (int)pow(2, i);
        for (int j = 0; j < SiSize; j++) {
            free(S[i][j]);
        }
        free(S[i]);
    }
    free(S);
        
    return res;
}
```