22/22 cases passed (0 ms)
Your runtime beats 100 % of c submissions
采用hash个，第一行字母hash值为1，第二行为2，第三行为3
```C []
char **findWords(char **words, int wordsSize, int *returnSize)
{
    char hash[26] = {2, 3, 3, 2, 1, 2, 2,
                     2, 1, 2, 2, 2, 3, 3,
                     1, 1, 1, 1, 2, 1,
                     1, 3, 1, 3, 1, 3};

    *returnSize = 0;
    if (0 == wordsSize) return NULL;
    int i, j, sum, len, ref, curr;
    char **res = (char**)malloc(wordsSize * sizeof(char*));
    for (i = 0; i < wordsSize; ++i){        
        len = strlen(words[i]);
        if (0 == len) continue;
        sum = 0;
        ref = hash[(words[i][0] - 'A') % 0x20];
        for (j = 1; j < len; ++j){
            curr = hash[(words[i][j] - 'A') % 0x20];
            sum += curr - ref;
        }
        if (0 == sum) res[(*returnSize)++] = words[i];
    }
    return res;
}
```
