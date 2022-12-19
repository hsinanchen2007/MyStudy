### 解题思路
纯C 动态规划 清清爽爽

### 代码

```c
static inline int min(int a, int b, int c)
{
    int d = a < b ? a : b;
    return d < c ? d : c;
}

int minDistance(char * word1, char * word2){
    /*
     * 状态方程：case1:word1和word2天然相等 => dp[i][j] = dp[i - 1][j - 1]
     *          case2:word1由插入、删除和替换变成word2 => dp[i][j] = 1 + MIN{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}
     * 边界条件：dp[0][j] = j, dp[i][0] = i
     * 初始条件：dp[0][0] = 0 （空出一格）
     */

    int row = 0;
    int col = 0;
    int lenOfWord1IsRow = strlen(word1);
    int lenOfWord2IsCol = strlen(word2);

    // 每个结点为一维数组的顺序表
    int** dp = (int**)malloc((lenOfWord1IsRow + 1) * sizeof(int*));
    for (row = 0; row <= lenOfWord1IsRow; row++)
    {
        dp[row] = (int*)malloc((lenOfWord2IsCol + 1) * sizeof(int));
    }

    // 初始条件、边界条件
    for (row = 0; row <= lenOfWord1IsRow; row++)  
    {
        dp[row][0] = row;
    }

    for (col = 0; col <= lenOfWord2IsCol; col++)
    {
        dp[0][col] = col;
    }

    // 状态转移方程
    for (row = 1; row <= lenOfWord1IsRow; row++ )
    {
        for (col = 1; col <= lenOfWord2IsCol; col++ )
        {
            if (word1[row - 1] == word2[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                dp[row][col] = 1 + min(dp[row][col - 1], dp[row - 1][col], dp[row - 1][col - 1]);
            }
        }
    }

    return dp[lenOfWord1IsRow][lenOfWord2IsCol];
}
```