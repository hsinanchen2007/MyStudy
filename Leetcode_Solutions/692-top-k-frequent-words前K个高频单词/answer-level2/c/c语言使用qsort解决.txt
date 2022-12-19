### 解题思路


### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct hash{
     char *str;
     int start;
     int count;
 }Hash;

// 仅按照字典序排序
 int cmp_dictionary(const void *para1, const void *para2)
 {
     return strcmp(*(char **)para1, *(char **)para2);
 }

// 首先按照计数排序，其次按照字典序排序
int cmp(const void *para1, const void *para2)
{
    Hash *tmp1 = (Hash *)para1;
    Hash *tmp2 = (Hash *)para2;
    if (tmp1->count == tmp2->count) {
        return strcmp(tmp2->str, tmp1->str);
    }
    return tmp1->count - tmp2->count;
}
// hash表
int current;
Hash *hash;

char **topKFrequent(char **words, int wordsSize, int k, int *returnSize)
{
    char **result = (char **)malloc(k * sizeof(char *));

    // 1.按照字典序排序words
    qsort(words, wordsSize, sizeof(words[0]), cmp_dictionary);

    // 2.遍历建立编号索引
    current = 0;
    hash = (Hash *)malloc(wordsSize * sizeof(Hash));
    memset(hash, 0, wordsSize * sizeof(Hash));

    for (int i = 0; i < wordsSize; current++) {
        int j = i + 1;
        hash[current].str = words[i];
        hash[current].start = i;
        hash[current].count = 1;
        while (j < wordsSize && !strcmp(words[i], words[j])) {
            // 3.遍历的同时计数
            j++;
            hash[current].count++;
        }
        i = j;
    }

    // 4.按照计数数组对hash表进行排序，若计数相同，则按照字典序排序
    qsort(hash, current, sizeof(hash[0]), cmp);

    // 5.将后k个字符串塞入结果数组
    current--;
    for (int i = 0; i < k; i++) {
        result[i] = (char *)malloc((strlen(hash[current].str) + 1) * sizeof(char));
        strcpy(result[i], hash[current].str);
        current--;
    }
    free(hash);
    *returnSize = k;
    return result;
}


```