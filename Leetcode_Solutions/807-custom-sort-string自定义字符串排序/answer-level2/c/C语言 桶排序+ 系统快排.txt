![image.png](https://pic.leetcode-cn.com/33389715a78523e32ee65325650cc40ec98460ed838444ec3eb55acf99e68874-image.png)

```
#define MAX_S 27
int g_index[MAX_S] = {0};
int Comp(void *a, void* b) {
    return g_index[(int)(*(char*)a - 'a')] - g_index[(int)(*(char*)b - 'a')];
}
char * customSortString(char * S, char * T){
    int len1 = strlen(S);
    int len2 = strlen(T);
    memset(g_index, 0, MAX_S * sizeof(int));
    
    for (int i = 0; i < len1; i++) {
        g_index[S[i] - 'a'] = i + 1;
    }
    int index = 0;
    char *str = (char*)malloc((len2 + 1) * sizeof(char));
    memcpy(str, T, (len2 + 1) * sizeof(char));
    qsort(str, len2, sizeof(char), Comp);
    return str;
}
```
