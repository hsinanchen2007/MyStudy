### 解题思路
递归+回溯

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 5000

void helper(int index, int *count, char *tem, char *S, char **ret)
{
    char cur = S[index];
    /* 结束 */
    if (index == strlen(S)) {
        strcpy(ret[(*count)++], tem);
        return;
    }
    /* 数字不处理 */
    if (cur >= '0' && cur <= '9') {
        helper(index + 1, count, tem, S, ret);
    } else {
        /* 不变 */
        tem[index] = cur;
        helper(index + 1, count, tem, S, ret);
        /* 变 */
        if (cur >= 'a' && cur <= 'z') {
            tem[index] = cur + 'A' - 'a';
        } else {
            tem[index] = cur + 'a' - 'A';
        }
        helper(index + 1, count, tem, S, ret);
    }
}

char ** letterCasePermutation(char * S, int* returnSize){
    if (S == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int len = strlen(S);
    int index = 0;
    int count = 0;
    int i;
    char *tem = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(tem, S);

    char **ret = (char **)malloc(sizeof(char *) * MAX);
    for (i = 0; i < MAX; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (len + 1));
        memset(ret[i], 0, sizeof(char) * (len + 1));
    }
    helper(index, &count, tem, S, ret);
    
    *returnSize = count;
    return ret;
    
}
```