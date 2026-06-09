### 解题思路
构造26个元素的hash，按照S的顺序给hash元素复制，S中不存在的复0，最先输出，然后根据元素值qsort一下就好了

### 代码

```c
int flag[26] = {0};
int comfunc(const void* a, const void* b) {
    char c = *(char*)a;
    char d = *(char*)b;
    int i = c - 'a';
    int j = d - 'a';
    return flag[i] - flag[j];
}
char * customSortString(char * S, char * T){
    memset(flag, 0, sizeof(int) * 26);
    int len = strlen(S);
    int lenT = strlen(T);
    for(int i = 0; i < strlen(S); i++) {
        flag[S[i]-'a'] = i + 1;
    }
    qsort(T, lenT, sizeof(char), comfunc);
    return T;
}
```