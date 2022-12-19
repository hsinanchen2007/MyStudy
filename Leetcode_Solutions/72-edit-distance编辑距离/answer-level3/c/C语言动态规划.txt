### 解题思路
动态规划，难点在状态和转移方程
状态：DP[i][j]表示前word1前i个字符和word2前j个字符转换的最小操作数。
根据变换规则分解子问题
删除/增加1个字符：DP[i - 1][j]和DP[i][j - 1]
替换1个字符：DP[i - 1][j - 1]
转换方程：
if(word1[i] == word1[j]){
    DP[i][j] = MIN((MIN(DP[i - 1][j], DP[i][j - 1]) + 1), DP[i - 1][j - 1])
} else {
    DP[i][j] = (MIN(DP[i - 1][j], DP[i][j - 1],  DP[i - 1][j - 1])) + 1
}

### 代码

```c

#define MIN(a, b) ((a > b) ? b : a)
#define PRINTF //printf

void FreeArray(int **pArray, int row)
{
    if(pArray == NULL){
        return;
    }
    for(int i = 0; i < row; i++){
        if(pArray[i] != NULL){
            free(pArray[i]);
        }
    }
    return;
}

int **MallocArray(int row, int col)
{
    int **pArray = malloc(row * sizeof(int *));
    if(pArray == NULL){
        goto ERR;
    }
    for(int i = 0; i < row; i++){
        pArray[i] = malloc(col * sizeof(int));
        if(pArray[i] == NULL){
            goto ERR;
        }
    }
    return pArray;
ERR:
    FreeArray(pArray, row);
    return NULL;
}

int minDistance(char * word1, char * word2){
    int lenWord1 = 0, lenWord2 = 0;
    lenWord1 = strlen(word1) + 1;
    lenWord2 = strlen(word2) + 1;
    int **pDisDp  = MallocArray(lenWord1, lenWord2);
    int iRet = 0;
    if(pDisDp == NULL){
        return iRet;
    }
    pDisDp[0][0] = 0;
    for(int i = 1; i < lenWord1; i++){
        pDisDp[i][0] = pDisDp[i - 1][0] + 1;
    }
    for(int i = 1; i < lenWord2; i++){
        pDisDp[0][i] = pDisDp[0][i - 1] + 1;
    }
    for(int i = 1; i < lenWord1; i++){
        for(int j = 1; j < lenWord2; j++){
            if(word1[i - 1] == word2[j - 1]){
                int minInc = (MIN(pDisDp[i][j - 1], pDisDp[i - 1][j]) + 1); // 增加一个字符
                pDisDp[i][j] = MIN(pDisDp[i - 1][j - 1], minInc);
            } else {
                int minInc = MIN(pDisDp[i][j - 1], pDisDp[i - 1][j]); // 增加1个字符
                minInc = MIN(minInc, pDisDp[i - 1][j - 1]); // 替换1个字符
                pDisDp[i][j] = (minInc + 1);
            }
            PRINTF("%d %d %d\n", i, j, pDisDp[i][j]);
        }
    }
    iRet = pDisDp[lenWord1 - 1][lenWord2 - 1];
    FreeArray(pDisDp, lenWord1);
    return iRet;
}
```