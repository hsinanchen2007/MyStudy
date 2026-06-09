### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct IndexList_S {
    int num;
    char *str;
} IndexList;
bool isEqual(const char *s1, const char *s2) {
    if (s1 == 0 || s2 == 0) {
        return false;
    }
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            return true;
        }
        s1++;
        s2++;
    }
    return false;
}
int cmp(const void *a, const void *b) {
    int sum = 0;
    
    sum = (((IndexList *)b)->num) - (((IndexList *)a)->num);
    if (sum == 0) {
        sum = strcmp(((IndexList *)a)->str, ((IndexList *)b)->str);
    }
    return sum;
}
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    char **data = (char **)calloc(1, sizeof(char *) * wordsSize);   //输出数据
    IndexList *list = (IndexList *)calloc(1, sizeof(IndexList) * wordsSize);
    int i, j;
    int m = 0;

    list[m].num++;
    list[m].str = words[0];
    m++;

    for (i = 1; i < wordsSize; i++) {
        for (j = 0; j < m; j++) {
            if (true == isEqual(list[j].str, words[i])) {
                (list[j].num)++;
                break;
            }
        }
        if (j == m) {
            (list[m].num) = 1;
            list[m].str = words[i];
            m++;
        }
    }

    qsort(list, m, sizeof(IndexList), cmp);

    for (i = 0; i < k; i++) {
        data[i] = (char *)malloc(sizeof(char) * (strlen(list[i].str) + 1));
        strcpy(data[i], list[i].str);
    }
    *returnSize = k;

    return data;
}
```