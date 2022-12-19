### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_CNT 5000

void DFS(char *stackStr, int maxLen, int leftLen, int rightLen, char **outStr, int *outCnt)
{
    if (leftLen < rightLen) {
        return;
    }

    if (leftLen == maxLen && rightLen == maxLen) {
        int size = 2 * maxLen + 1;
        outStr[*outCnt] = (char*)calloc(size, sizeof(char));
        if (outStr[*outCnt] == 0) {
            return;
        }
        memcpy(outStr[*outCnt], stackStr, size * sizeof(char));
        (*outCnt)++;
        return;
    }

    if (leftLen < maxLen) {
        stackStr[leftLen + rightLen] = '(';
        DFS(stackStr, maxLen, leftLen + 1, rightLen, outStr, outCnt);
        stackStr[leftLen + rightLen] = 0;
    }

    if (rightLen < maxLen && leftLen > rightLen) {
        stackStr[leftLen + rightLen] = ')';
        DFS(stackStr, maxLen, leftLen, rightLen + 1, outStr, outCnt);
        stackStr[leftLen + rightLen] = 0;
    }
}

char ** generateParenthesis(int n, int* returnSize) 
{
    char **retStr = 0;
    char *stack = 0;
    int outCnt = 0;

    retStr = (char**)calloc(MAX_CNT, sizeof(char*));
    if (retStr == 0) {
        return 0;
    }

    stack = (char*)calloc(2 * n + 1, sizeof(char));
    if (stack == 0) {
        free(retStr);
        return 0;
    }

    DFS(stack, n, 0, 0, retStr, &outCnt);
    *returnSize = outCnt;
    return retStr;
}
```