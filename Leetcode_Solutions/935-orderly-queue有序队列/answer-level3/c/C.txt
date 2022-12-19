### 解题思路
C

### 代码

```c
int char_cmp(const void* str1, const void* str2)
{
    return *(char*)str1 - *(char*)str2;
}
char * orderlyQueue(char * S, int K){
    if(K > 1) {
    qsort(S, strlen(S), sizeof(char), char_cmp);
    return S;
    }
    else  {
        char *S1 = (char*)malloc(strlen(S) * sizeof(char));
        char *S2 = (char*)malloc(2 * strlen(S) * sizeof(char));
        char z = 'z';
        for (int i = 0; i < strlen(S); i++){
            S1[i] = S[i];
            S2[i]= S[i];
            S2[strlen(S)+i]=S[i];
        }
        qsort(S1, strlen(S), sizeof(char), char_cmp);
        int flag = 0;
        for (int i = 0; i < strlen(S); i++){
            if(S[i] == S1[0]) {
                if(S[i+1]<=z){
                    flag=i;
                    z = S[i+1];
                }
            }
        }
        for (int i = flag; i < strlen(S)+flag; i++){
            S[i-flag] = S2[i];
        }
        return S;
    }
}
```