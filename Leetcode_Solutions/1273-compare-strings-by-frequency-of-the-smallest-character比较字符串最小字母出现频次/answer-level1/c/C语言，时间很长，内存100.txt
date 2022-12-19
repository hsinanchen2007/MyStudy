### 解题思路
最基础解法，O（n*n)复杂度

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int freq(char *str) {
    int len = strlen(str);
    int sum[26] = {0};
    for (int i = 0; i < len; i++) {
        sum[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (sum[i] != 0) {
            return sum[i];
        }
    }
    return 0;
}
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * queriesSize);
    memset(res, 0, sizeof(int) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (freq(queries[i]) < freq(words[j])) {
                res[i]++;
            }
        }
    }
    *returnSize = queriesSize;
    return res;
}
```