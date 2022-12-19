### 解题思路
没啥思路，基本DFS
### 代码

```c

#define MAX_RET 10000

char ***g_ans;
int g_ansSize;

char *substr(char *s, int l, int r) {
    char *sub = malloc(r - l + 2);
    int index = 0;
    while (l <= r) {
        sub[index++] = s[l++];
    }
    sub[index] = '\0';
    return sub;
}

bool isPalindrome(char *s, int l, int r) {
    if (l == r) {
        return true;
    }
    while (l < r) {
        if (s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

void dump(char **subs, int subSize) {
    for (int i = 0; i < subSize; ++i) {
        printf("%s, ", subs[i]);
    }
    printf("\n");
}

void copyToAns(char **subs, int subSize, int *retColSize) {
    g_ans[g_ansSize] = malloc(sizeof(char *) * subSize);
    retColSize[g_ansSize] = subSize;
    for (int i = 0; i < subSize; ++i) {
        g_ans[g_ansSize][i] = malloc(sizeof(char) * (strlen(subs[i]) + 1)); // one more char for '\0'
        strcpy(g_ans[g_ansSize][i], subs[i]);
    }
    ++g_ansSize;
}

void dfs(char *s, int len, int pos, char **subs, int subSize, int *retColSize) {
    if (pos == len) {
            // dump(subs, subSize);
        copyToAns(subs, subSize, retColSize);
        return;
    }
    for (int i = pos; i < len; ++i) {
        if (isPalindrome(s, pos, i)) {
            subs[subSize] = substr(s, pos, i);
            dfs(s, len, i + 1, subs, subSize + 1, retColSize);
            free(subs[subSize]);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    g_ansSize = 0;
    g_ans = (char ***)malloc(sizeof(char *) * MAX_RET);
    char **tmpSubs = malloc(sizeof(char *) * strlen(s));    // s can be splited into strlen(s) sub strings if length of each sub string is 1
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_RET);
    dfs(s, strlen(s), 0, tmpSubs, 0, *returnColumnSizes);
    *returnSize = g_ansSize;

    free(tmpSubs);
    return g_ans;
}
```