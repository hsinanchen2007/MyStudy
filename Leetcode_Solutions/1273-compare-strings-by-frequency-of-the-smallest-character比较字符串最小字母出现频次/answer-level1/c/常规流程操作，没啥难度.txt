### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int calNum(char *words)
{
    int hash_map[26] = {0};
    int i = 0;
    
    while(words[i] != '\0') {
        hash_map[words[i] - 'a']++;
        i++;
    }

    for (i = 0; i < 26; i++) {
        if (hash_map[i]) {
            return hash_map[i];
        }
    }
    return 0;
}

int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    int *a = calloc(queriesSize, sizeof(int));
    int *b = calloc(wordsSize, sizeof(int));
    int *c = calloc(queriesSize, sizeof(int));
    int i = 0;

    for (i = 0; i < queriesSize; i++) {
        a[i] = calNum(queries[i]);
        //printf("%d ", a[i]);
    }
   // printf("\n");

    for (i = 0; i < wordsSize; i++) {
        b[i] = calNum(words[i]);
        //printf("%d ", b[i]);
    }

    int cnt = 0;
    int j = 0;
    for (i = 0; i < queriesSize; i++) {
        for (j = 0; j < wordsSize; j++) {
            if (b[j] > a[i]) {
                cnt++;
            }
        }
        c[i] = cnt;
        cnt = 0;
    }
    *returnSize = queriesSize;
    
    return c;
}
```