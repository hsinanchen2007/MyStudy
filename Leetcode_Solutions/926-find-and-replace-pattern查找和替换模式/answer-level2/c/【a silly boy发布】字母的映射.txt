![image.png](https://pic.leetcode-cn.com/f061df866d16b06a970838402b840978b71eaaf1c88dfa7c669903ea95ca0ac9-image.png)

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 26

char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize)
{
    *returnSize = 0;

    if ((words == NULL) || (wordsSize == 0) || (pattern == NULL)) {
        return NULL;
    }
    int i;
    int j = 0;
    int k = 0;
    int patternMap[MAXSIZE];

    memset(patternMap, 0, MAXSIZE * sizeof(int));

    char **returnValue = (char **)malloc(wordsSize * sizeof(char *));
    int patternLen = strlen(pattern);

    for (i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) != patternLen) {
            continue;
        }
        memset(patternMap, 0, MAXSIZE * sizeof(int));
        for (j = 0; j < patternLen; j++) {
            if (patternMap[pattern[j] - 'a'] == 0) {
                for (k = 0; k < j; k++) {
                    if (words[i][j] == patternMap[pattern[k] - 'a']) {
                        goto _END_;  
                    }
                }
                patternMap[pattern[j] - 'a'] = words[i][j];

            } else {
                if (patternMap[pattern[j] - 'a'] != words[i][j]) {
                    goto _END_;
                }
            }
        }
        returnValue[*returnSize] = (char *)malloc((patternLen + 1) * sizeof(char));
        memcpy(returnValue[*returnSize], words[i], (patternLen + 1) * sizeof(char));
        (*returnSize)++;
    _END_:
        ;
    }

    return returnValue;
}
```
