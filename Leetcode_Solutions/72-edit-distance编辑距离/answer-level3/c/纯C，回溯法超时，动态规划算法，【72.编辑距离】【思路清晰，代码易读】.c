### 解题思路
方法一：回溯法
每个字符有以下四种操作方法
0，字符不变
1，插入一个字符
2，删除一个字符
3，替换一个字符
注，能解决问题，但是随着字母的增加，耗时指数级增加，最终超时，并且无优化空间

方法二：动态规划算法
1,使用 dp[m][n] 表示 word1 的m个字符 和 word2 的n个字符的最少操作数
2,找到 dp[m][n] 和 dp[m-1][n-1] 、dp[m-1][n]、dp[m][n-1] 之间的关系
3,发现 if(word1[m] == word2[n]) 则 dp[m][n]=1+MIN(dp[m-1][n-1]-1,dp[m-1][n],dp[m][n-1]);
  从 dp[m-1][n-1]转变到 dp[m][n] 由于最后一个字符相等，所以操作数不用加一
4,if(word1[m] ！= word2[n]) 则 dp[m][n]=1+MIN(dp[m-1][n-1],dp[m-1][n],dp[m][n-1]);

### 代码

```c
//方法二：动态规划算法
//1,使用 dp[m][n] 表示 word1 的m个字符 和 word2 的n个字符的最少操作数
//2,找到 dp[m][n] 和 dp[m-1][n-1] 、dp[m-1][n]、dp[m][n-1] 之间的关系
//3,发现 if(word1[m] == word2[n]) 则 dp[m][n]=1+MIN(dp[m-1][n-1]-1,dp[m-1][n],dp[m][n-1]);
//  从 dp[m-1][n-1]转变到 dp[m][n] 由于最后一个字符相等，所以操作数不用加一
//4,if(word1[m] ！= word2[n]) 则 dp[m][n]=1+MIN(dp[m-1][n-1],dp[m-1][n],dp[m][n-1]);

#define     MIN(a, b, c)    ((a) < ((b) < (c) ? (b) : (c)) ? (a) : ((b) < (c) ? (b) : (c)))
int minDistance(char * word1, char * word2){
    int     i       = 0;
    int     j       = 0;
    int     iLen1   = strlen(word1);
    int     iLen2   = strlen(word2);
    int     dp[iLen1 + 1][iLen2 + 1];

    //1,初始化
    for (i = 0; i <= iLen1; i++)
    {
        dp[i][0] = i;
    }
    for (j = 0; j <= iLen2; j++)
    {
        dp[0][j] = j;
    }

    //2,动态规划计算最终解
    for (i = 1; i <= iLen1; i++)
    {
        for (j = 1; j <= iLen2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = 1 + MIN(dp[i-1][j-1] - 1, dp[i - 1][j], dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = 1 + MIN(dp[i-1][j-1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

/*
    for (i = iLen1; i >= 0; i--)
    {
        for (j = 0; j <= iLen2; j++)
        {
            printf("%02d, ", dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[iLen1][iLen2];
}

/*
//方法一：回溯法
//每个字符有以下四种操作方法
//0，字符不变
//1，插入一个字符
//2，删除一个字符
//3，替换一个字符
#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
#define     MIN(a, b)   ((a) < (b) ? (a) : (b))
int backTrackDistance(char* pWord1, char* pWord2, int* iMin, int iStep){
    int     iLen1       = strlen(pWord1);
    int     iLen2       = strlen(pWord2);
    int     iStepLen1   = iStep;
    int     iStepLen2   = iStep;
    int     iStepLen3   = iStep;
    int     iStepLen4   = iStep;
    int     iMinStep    = iStep;

    //1,结束条件
    if (((iLen1 == 0) && (iLen2 == 0)) || 
        ((iLen1 == iLen2) && (0 == memcmp(pWord1, pWord2, iLen1))))
    {
        //剩下两部分相同，不需要再操作
        if (iStep < *iMin)
        {
            *iMin = iStep;
        }
        iMinStep = iStep;
        return iMinStep;
    }

    //2,回溯操作
    if (pWord1[0] == pWord2[0])
    {
        //第一个字符相同，则字符不变，进行下一步
        iStepLen1 = backTrackDistance(&pWord1[1], &pWord2[1], iMin, iStep);
        iMinStep = MIN(iMinStep, iStepLen1);
    }

    if (iLen1 <= iLen2)
    {
        //word1 长度 < word2 长度，则插入一个字符
        iStepLen2 = backTrackDistance(&pWord1[0], &pWord2[1], iMin, iStep + 1);
        iMinStep = MIN(iMinStep, iStepLen2);
    }
    
    if (iLen1 >= iLen2)
    {
        //word1 长度 >word2 长度，则删除一个字符
        iStepLen3 = backTrackDistance(&pWord1[1], &pWord2[0], iMin, iStep + 1);
        iMinStep = MIN(iMinStep, iStepLen3);
    }

    if ((pWord1[0] != pWord2[0]) && (pWord1[0] != '\0') && (pWord2[0] != '\0'))
    {
        //替换一个字符
        iStepLen4 = backTrackDistance(&pWord1[1], &pWord2[1], iMin, iStep + 1);
        iMinStep = MIN(iMinStep, iStepLen4);
    }

    return iMinStep;
}

int minDistance(char * word1, char * word2){
    int     iLen1       = strlen(word1);
    int     iLen2       = strlen(word2);
    int     iMaxLen     = MAX(iLen1, iLen2);
    char*   pWord1      = NULL;
    char*   pWord2      = NULL;
    int     iMin        = iMaxLen;

    //1，初始化
    pWord1 = (char*)malloc(sizeof(char) * (iMaxLen + 1));
    memset(pWord1, 0x00, sizeof(char) * (iMaxLen + 1));
    memcpy(pWord1, word1, sizeof(char) * iLen1);

    pWord2 = (char*)malloc(sizeof(char) * (iLen2 + 1));
    memset(pWord2, 0x00, sizeof(char) * (iLen2 + 1));
    memcpy(pWord2, word2, sizeof(char) * iLen2);

    //2，回溯调用
    backTrackDistance(pWord1, pWord2, &iMin, 0);

    //3，释放空间
    free(pWord1);
    free(pWord2);

    //4，返回
    return iMin;
}
*/
```