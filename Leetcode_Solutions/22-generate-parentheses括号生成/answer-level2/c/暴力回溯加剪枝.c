### 解题思路
剪枝的条件和结束的条件考虑清楚就没问题了。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Generator(int left, int right, int n, char* str, int idx, char** retArray, int* retSize)
{
    if (left >= n && right >=n) { // 结束条件
        retArray[(*retSize)] = (char*)malloc(sizeof(char) * (2 * n + 1));
        memcpy(retArray[(*retSize)], str, (sizeof(char) * (2 * n + 1)));
        retArray[(*retSize)][2 * n] = '\0';
        //printf("%s\n", retArray[(*retSize)]);
        (*retSize)++;
        return;
    }
    // 左没放完放左
    if (left < n) {
        str[idx] = '(';
        Generator(left + 1, right, n, str, idx + 1, retArray, retSize);
    }
    // 右没放完，条件为小于左,否则剪枝
    if (right < n && right < left) {
        str[idx] = ')';
        Generator(left, right + 1, n, str, idx + 1, retArray, retSize);
    }
    return;
}

char ** generateParenthesis(int n, int* returnSize){
    char* str = (char*)malloc(sizeof(char) * (2 * n + 1));
    char** retArray = (char**)malloc(sizeof(char*) * 200000);
    *returnSize = 0;
    Generator(0, 0, n, str, 0, retArray, returnSize);
    free(str);
    //printf("%d\n", *returnSize);
    //for (int i = 0; i < *returnSize; i++) {
    //    printf("%s\n", retArray[i]);
    //}
    return retArray;
}
```