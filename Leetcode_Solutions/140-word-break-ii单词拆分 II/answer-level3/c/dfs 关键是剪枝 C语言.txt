### 解题思路
重点：fail数组来判断当前位置是否可以往下走
result数组：记录字符串s匹配的单词在wordDict的下标


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024

void dfs(char *s, int pos, char **res, int *returnSize, char **wordDict, int wordDictSize, int *result, int idx, int *fail)
{
    
    if (s[pos] == '\0') { //得到一个结果
        // 先算长度
        int length = 0;
        for (int i = 0; i < idx; ++i) {
            length += strlen(wordDict[result[i]]) + 1;
        }
        res[*returnSize] = (char *)malloc(length * sizeof(char));
        int p = 0;
        for (int i = 0; i < idx; i++) {
            for (int j = 0; j < strlen(wordDict[result[i]]); j++) {
                res[*returnSize][p++] = wordDict[result[i]][j];
            }
            res[*returnSize][p++] = ' ';
        }
        res[*returnSize][length - 1] = '\0';
        (*returnSize)++;
        return;
    }
    //如果pos位置失败，直接跳过
    if (fail[pos] == 1) {
        return;
    }
    
    // 如果遍历完wordDict，未能匹配，fail[pos] 置 1
    int fail_cnt = 0; //记录pos位置匹配wordDict 失败的计数，如果pos位置无法匹配wordDict里所有单词，则fail[pos] = 1
    for (int i = 0; i < wordDictSize; i++) {
        if (pos == 0) {
            memset(fail, 0, MAX_SIZE * sizeof(int));
        }
        int len = strlen(wordDict[i]);
        if (fail[pos + len] == 1) { // 这里加判断！！！！如果pos + len 位置不满足，那么pos位置匹配完这个单词也不会满足
            fail_cnt++;
            continue;
        }
        if (strlen(s) - pos >= len && memcmp(s + pos, wordDict[i], len) == 0) {
            result[idx] = i; //匹配到单词，记录在result里
            dfs(s, pos + len, res, returnSize, wordDict, wordDictSize, result, idx + 1, fail);
        } else {
                fail_cnt++;  // 这里判断一下
        }
    }
        
    if (fail_cnt == wordDictSize) {
        fail[pos] = 1;
    }
    return;
}

char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    size_t len = strlen(s);
    
    char **res = (char **)malloc(sizeof(char *) *MAX_SIZE);
    *returnSize = 0;
    

    int *result = (int *)malloc(len * sizeof(int));
    memset(result, -1, len * sizeof(int));
    
    int *fail = (int *)calloc(MAX_SIZE, sizeof(int));

    dfs(s, 0, res, returnSize, wordDict, wordDictSize, result, 0, fail);
    
    return res;
}
```