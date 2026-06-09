1、考虑自身有重复，直接返回
2、拼接前查看拼接的两个是否有重复，有重复直接返回
3、有时候选择不是最优解，按照字符串由长到短排序
4、是否有重复字符使用hash来判断，简单易懂
```
int GetTwoRepeat(char s1[], char s2[])
{
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    if (lens1 <= 0 && lens2 <= 0) {
        return false; 
    }
    int *hash = (int *)malloc(sizeof(int) * 27);
    memset(hash, 0, sizeof(int) * 27);
    for (int i = 0; i < lens1; i++) {
        hash[s1[i] - 'a']++;
    }

    for (int i = 0; i < lens2; i++) {
        hash[s2[i] - 'a']++;
    }
    for (int i = 0; i < 27; i++) {
        if (hash[i] > 1) {
            free(hash);
            return false;
        }
    }
    free(hash);
    return true;
}
int GetOneRepeat(char s[]) 
{
    int lens1 = strlen(s);
    if (lens1 <= 0) {
        return false;
    }
    int *hash = (int *)malloc(sizeof(int) * 27);
    memset(hash, 0, sizeof(int) * 27);
    for (int i = 0; i < lens1; i++) {
        hash[s[i] - 'a']++;
    }
    for (int i = 0; i < 27 ; i++) {
        if (hash[i] > 1) {
            free(hash);
            return false;
        }
    }
    free(hash);
    return true;
}
int Cmp(const void *a, const void *b)
{
    return strlen(*(char**)b) - strlen(*(char**)a);
}
int maxLength(char ** arr, int arrSize){
    char *str = (char *)malloc(sizeof(char) * 417);
    memset(str, '\0', sizeof(char) * 417);
    int i = 0;
    int j = 0;
    int sum = 0;
    int max = 0;
    qsort(arr, arrSize, sizeof(arr), Cmp);
    for (i = 0; i < arrSize; i++) {
        str = strcpy(str, "\0");
        sum = 0;
        strcpy(str, arr[i]);
        if (GetOneRepeat(str) == false) {
            continue;
        }
        for (j = 0; j < arrSize; j++) {
            if (j != i && GetTwoRepeat(str, arr[j])) {
                strcat(str, arr[j]);
            } else {
                continue;
            }
        }
        
        sum = strlen(str);
        if (sum > max) {
            max = sum;
        }
    }
    free(str);
    return max;
}


```
