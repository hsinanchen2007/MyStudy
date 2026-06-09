利用hash 和 快速排序

### 代码

```c
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct hashStru_
{
    int idx;
    int num;
}hashStru;
int compare(const void *a, const void *b)
{
    hashStru *aa = (hashStru*)a;
    hashStru *bb = (hashStru*)b;
    return bb->num - aa->num;
}
char * frequencySort(char * s){
    hashStru hash[256];
    memset(hash, 0, sizeof(hash));
    int len = strlen(s);
    int i;
    int idx;
    if (s == NULL || len == 0) {
        return s;
    }
    for (i = 0; i < len; i++) {
        idx = s[i] - ' ';
        hash[idx].idx = idx;
        hash[idx].num++;
    }
    char *ss = malloc(sizeof(char)*(len+1));
    qsort(hash, 256, sizeof(hashStru),compare);  
    int k = 0;
    for (i = 0; i < 256; i++) {
        for (int j = 0; j < hash[i].num; j++) {
            ss[k] = hash[i].idx + ' ';
            k++;
        }
    }
    ss[k] = '\0';
    return ss;
}
```