### 解题思路
方法一：回溯法
1,  结束条件当 iStep=m+n-1 时则找到了一个答案
2,  向右或者向下探寻一步，回溯调用
注：想保留每个答案，但是发现随着 m,n 的增大，空间开销太大，虽然算法正确，但也只能放弃

方法二：回溯法优化
1,  保存中间结果，用例结果太大，空间不够
2,  不保存中间结果，只用一个数组空间，求出最终路径的条数
3,  超时优化
优化一：向右走到头，或者向下走到头，就可以直接结束返回
注：不保存每个答案，只需要一个 m * n  的数组即可，但是发现随着 m,n 的增大，执行时间是指数级增加，也只能放弃

方法三：动态规划算法，才是此题的正解
1,找寻 f(m, n) 和 f(m-1, n)、f(m, n-1)、f(m, n)，之间的关系
2,画图就可以发现 f(m, n) = f(m-1, n) + f(m, n-1),知道了这个关系，剩下的就只是代码了
3,动态规划法优化，减少空间，只需要dp[m]大小的数组即可

### 代码

```c
//方法三：动态规划算法
//1,找寻 f(m, n) 和 f(m-1, n)、f(m, n-1)、f(m, n)，之间的关系
//2,画图就可以发现 f(m, n) = f(m-1, n) + f(m, n-1),知道了这个关系，剩下的就只是代码了
//3,动态规划法优化，减少空间，只需要dp[m]大小的数组即可
int uniquePaths(int m, int n){
    int     i       = 0;
    int     j       = 0;
    int     dp[m];

    //1,初始化
    for (j = 0; j < m; j++)
    {
        dp[j] = 1;
    }

    //2,动态规划求出最终解
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            dp[j] = dp[j - 1] + dp[j];
        }
    }

    //3,返回 dp[m-1]
    return dp[m - 1];
}


/*
//方法二：回溯法优化
//1,保存中间结果，用例结果太大，空间不够
//2,不保存中间结果，只用一个数组空间，求出最终路径的条数
//3,超时优化
//优化一：向右走到头，或者向下走到头，就可以直接结束返回
void backTrackPath(int m, int n, int** pStep, int* pRetPath, int iStep){
    int     i       = 0;
    int     iRow    = 0;
    int     iCol    = 0;

//    printf("[1][m=%d][n=%d][iStep=%d][Ret=%d][%d-%d]\n", 
//            m, n, iStep, *pRetPath, pStep[iStep][0], pStep[iStep][1]);

    //1,结束条件
    if (iStep == m + n - 1)
    {
        *pRetPath += 1;
        return;
    }

    //3,设置坐标值，回溯调用
    iRow = pStep[iStep][0];
    iCol = pStep[iStep][1];

    if (iCol + 1 < m)
    {
        //向右一步
        if (iRow >= n - 1)
        {
            //优化一：向右走时，如果已经是最下一行，则直接结束
            *pRetPath += 1;
            return;
        }
        else
        {
            pStep[iStep + 1][0] = iRow;
            pStep[iStep + 1][1] = iCol + 1;
            backTrackPath(m, n, pStep, pRetPath, iStep + 1);
        }
    }

//    printf("[2][m=%d][n=%d][iStep=%d][Ret=%d][%d-%d]\n", 
//            m, n, iStep, *pRetPath, pStep[iStep][0], pStep[iStep][1]);

    if (iRow + 1 < n)
    {
        //向下一步
        if (iCol >= m - 1)
        {
            //优化二：向下走时，如果已经是最后一列，则直接结束
            *pRetPath += 1;
            return;
        }
        else 
        {
            pStep[iStep + 1][0] = iRow + 1;
            pStep[iStep + 1][1] = iCol;
            backTrackPath(m, n, pStep, pRetPath, iStep + 1);
        }
    }

//    printf("[3][m=%d][n=%d][iStep=%d][Ret=%d][%d-%d]\n", 
//            m, n, iStep, *pRetPath, pStep[iStep][0], pStep[iStep][1]);

    return;
}

int uniquePaths(int m, int n){
    int     i               = 0;
    int     j               = 0;
    int**   pStep           = NULL;
    int     iRetPath        = 0;

    if ((m == 0) && (n == 0)) return 0;
    if ((m == 1) && (n == 1)) return 1;

    //1,初始化
    pStep = (int**)malloc(sizeof(int*) * (m + n));
    for (i = 0; i < (m + n); i++)
    {
        pStep[i] = (int*)malloc(sizeof(int) * 2);
        memset(pStep[i], 0x00, sizeof(int) * 2);
    }

    //2,回溯调用
    backTrackPath(m, n, pStep, &iRetPath, 1);

    //4,返回
    return iRetPath;
}
*/
/*
//方法一：回溯法
//回溯函数
//1,结束条件当iStep=m+n-1时则找到了一个答案
//2,向右或者向下探寻一步，回溯调用
void backTrackPath(int m, int n, int*** pStep, int* pRetPath, int iStep){
    int     i       = 0;
    int     iRow    = 0;
    int     iCol    = 0;

    //1,结束条件
    if (iStep == m + n - 1)
    {
        pStep[(*pRetPath) + 1] = (int**)malloc(sizeof(int*) * (m + n));
        for (i = 0; i < (m + n); i++)
        {
            pStep[(*pRetPath) + 1][i] = (int*)malloc(sizeof(int) * 2);
            memcpy(pStep[(*pRetPath) + 1][i], pStep[(*pRetPath)][i], sizeof(int) * 2);
        }
        *pRetPath += 1;
        return;
    }

    //2,申请空间保存每步坐标
    if (iStep == 1)
    {
        pStep[*pRetPath] = (int**)malloc(sizeof(int*) * (m + n));
        for (i = 0; i < (m + n); i++)
        {
            pStep[*pRetPath][i] = (int*)malloc(sizeof(int) * 2);
            memset(pStep[*pRetPath][i], 0x00, sizeof(int) * 2);
        }
    }

//    printf("[1][m=%d][n=%d][iStep=%d][Ret=%d][%d-%d]\n", 
//            m, n, iStep, *pRetPath, pStep[*pRetPath][iStep][0], pStep[*pRetPath][iStep][1]);

    //3,设置坐标值，回溯调用
    iRow = pStep[*pRetPath][iStep][0];
    iCol = pStep[*pRetPath][iStep][1];

    if (iCol + 1 < m)
    {
        //向右一步
        pStep[*pRetPath][iStep + 1][0] = iRow;
        pStep[*pRetPath][iStep + 1][1] = iCol + 1;
        backTrackPath(m, n, pStep, pRetPath, iStep + 1);
    }

    if (iRow + 1 < n)
    {
        //向下一步
        pStep[*pRetPath][iStep + 1][0] = iRow + 1;
        pStep[*pRetPath][iStep + 1][1] = iCol;
        backTrackPath(m, n, pStep, pRetPath, iStep + 1);
    }

    return;
}

int uniquePaths(int m, int n){
    int     i           = 0;
    int     j           = 0;
    int***  pStep       = NULL;
    int     iPathMax    = 50000;
    int     iRetPath    = 0;

    return 500;
    if ((m == 0) && (n == 0)) return 0;
    if ((m == 1) && (n == 1)) return 1;

    //1,初始化
    pStep = (int***)malloc(sizeof(int**) * iPathMax);
    memset(pStep, 0x00, sizeof(int**) * iPathMax);

    //2,回溯调用
    backTrackPath(m, n, pStep, &iRetPath, 1);

    //3,释放空间
    for (i = 0; i < iRetPath; i++)
    {
        for (j = 0; j < (m + n); j++)
        {
            free(pStep[i][j]);
        }
    }

    //4,返回
    return iRetPath;
}
*/
```