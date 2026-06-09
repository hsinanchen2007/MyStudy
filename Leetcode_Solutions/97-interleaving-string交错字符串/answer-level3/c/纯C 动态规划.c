### 解题思路
二维动态规划 存在性问题 OR AND

### 代码

```c
bool isInterleave(char * s1, char * s2, char * s3){
    /*
     * 状态方程：dp[i][j] = OR{ dp[i(j)-1] AND (s1(2)[i(j)-1] = s3[i+j-1]) }
     * 初始条件：dp[0][0] = true
     * 边界情况：i = 0 OR j = 0
     */
    
    int indexOfS1 = 0;
    int indexOfS2 = 0;
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int length3 = strlen(s3);
    
    if (length1 + length2 != length3)
    {
        return false;
    }
    
    bool** dp = (bool**)malloc(sizeof(bool*) * (length1 + 1));
    for (indexOfS1 = 0; indexOfS1 <= length1; indexOfS1++)
    {
        dp[indexOfS1] = (bool*)malloc(sizeof(bool) * (length2 + 1));
    }

    for (indexOfS1 = 0; indexOfS1 <= length1; indexOfS1++)
    {
        for (indexOfS2 = 0; indexOfS2 <= length2; indexOfS2++)
        {
            if (0 == indexOfS1 && 0 == indexOfS2)
            {
                dp[indexOfS1][indexOfS2] = true;
            }
            else if (0 == indexOfS1)
            {
                dp[indexOfS1][indexOfS2] = dp[0][indexOfS2-1] &&             \
                                           s2[indexOfS2-1] == s3[indexOfS2-1];
            }
            else if (0 == indexOfS2)
            {
                dp[indexOfS1][indexOfS2] = dp[indexOfS1-1][0] &&             \
                                           s1[indexOfS1-1] == s3[indexOfS1-1];
            }
            else
            {
                dp[indexOfS1][indexOfS2] = dp[indexOfS1][indexOfS2-1] &&                   \
                                           s2[indexOfS2-1] == s3[indexOfS1+indexOfS2-1] || \
                                           dp[indexOfS1-1][indexOfS2] &&                   \
                                           s1[indexOfS1-1] == s3[indexOfS1+indexOfS2-1];
            }
        }
    }
    
    return dp[length1][length2];   
}
```