### 解题思路
纯C 动态规划 清清爽爽

### 代码

```c
bool isMatch(char * s, char * p){
    /*
     * s为行，p为列
     * 状态方程： case1: if "?", dp[i][j] = dp[i - 1][j - 1] 左上角传递给右下角
     *            case2: if "*", dp[i][j] = dp[i][j - 1] 左下角传递给右下角，作为空字符
     *                           dp[i][j] = dp[i - 1][j] 右上角传递给右下角，作为任意字符
     * 初始条件： dp[0][0] = true;
     * 边界条件： dp[0][j] = false; dp[i][0] = dp[i - 1][0]
     */

    if (NULL == s || NULL == p)
    {
        return false;
    }

    int lenOfS = strlen(s);
    int lenOfP = strlen(p);
    int row = 0;
    int col = 0;

    bool** ppbIsMatch = (bool**)malloc((lenOfP + 1) * sizeof(bool*));
    for (row = 0; row <= lenOfP; row++)
    {
        ppbIsMatch[row] = (bool*)malloc((lenOfS + 1) * sizeof(bool));
        memset(ppbIsMatch[row], false, (lenOfS + 1) * sizeof(bool));
    }

    ppbIsMatch[0][0] = true;

    for (row = 1; row <= lenOfP; row++)
    {
        if ('*' == *(p + row - 1))
        {
            ppbIsMatch[row][0] = ppbIsMatch[row - 1][0];
        }
    }

    for (row = 1; row <= lenOfP; row++)
    {
        for (col = 1; col <= lenOfS; col++)
        {
            if (*(s + col - 1) == *(p + row - 1) || '?' == *(p + row - 1))
            {
                ppbIsMatch[row][col] = ppbIsMatch[row - 1][col - 1];
            }
            else if ('*' == *(p + row - 1))
            {
                ppbIsMatch[row][col] = ppbIsMatch[row - 1][col] || ppbIsMatch[row][col - 1];
            }
        }
    }

    return ppbIsMatch[lenOfP][lenOfS];
}
```