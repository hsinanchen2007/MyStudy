### 解题思路
方法一：两头循环的方法，避免了一次循环解决不了的各种特殊情况
    1,正循环能够找出从头开始完整的配对情况
    2,反循环能够超出从尾开始完整的配对情况

方法二：动态规划算法,遍历字符串截取两个字符判断
    1，() 则 dp[i] = dp[i-2] + 2;
    2, )) 则 if(s[i - dp[i-1] -1] == '(')  dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2
    3, 其他情况 dp[i]=0
### 代码

```c
//方法二：动态规划算法
int longestValidParentheses(char * s){
    int     i       = 0;
    int     iSlen   = strlen(s);
    int*    dp      = NULL;
    int     iMaxLen = 0;

    if ((NULL == s) || (iSlen <= 1))
    {
        return 0;
    }

    //申请动态数组dp 用于保存动态数组的值
    dp = (int *)malloc(sizeof(int) * iSlen);
    memset(dp, 0x00, sizeof(int) * iSlen);

    //动态算法:遍历字符串截取两个字符判断
    //1，() 则 dp[i] = dp[i-2] + 2;
    //2, )) 则 if(s[i - dp[i-1] -1] == '(')  dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2
    for (i = 1; i < iSlen; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
            }
            else if ((i - dp[i - 1] > 0) && (s[i - dp[i - 1] - 1] == '('))
            {
                dp[i] = dp[i - 1] + (((i - dp[i - 1]) >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }

            if (dp[i] > iMaxLen) iMaxLen = dp[i]; 
        }
    }
    return iMaxLen;
}



/*
//方法一：两头循环的方法，避免了一次循环解决不了的各种特殊情况
//正循环能够找出从头开始完整的配对情况
//反循环能够超出从尾开始完整的配对情况
int longestValidParentheses(char * s){
    int     i       = 0;
    int     j       = 0;
    int     iLeft   = 0;
    int     iRight  = 0;
    int     iMaxLen = 0;
    int     iRetLen = 0;
    int     iTmpLen = 0;
    int     iSlen   = strlen(s);

    for (i = 0; i < iSlen; i++)
    {
//        printf("i=%d, s=%c, left=%d, right=%d, max=%d\n", i, s[i], iLeft, iRight, iMaxLen);
        if ((iLeft == 0) && (s[i] == ')')) continue;

        if (s[i] == '(') iLeft += 1;
        if (s[i] == ')') iRight += 1;

        if ((0 != iLeft) && (iRight == iLeft))
        {
            //匹配成功
            iTmpLen = iLeft * 2;
        }
        if ((0 != iLeft) && (iRight > iLeft))
        {
            iLeft = 0;
            iRight = 0;
        }

        if (iMaxLen < iTmpLen) iMaxLen = iTmpLen;
    }

    iLeft = 0;
    iRight = 0;
    iTmpLen = 0;
    
    for (i = iSlen - 1; i >= 0; i--)
    {
//        printf("i=%d, s=%c, left=%d, right=%d, max=%d\n", i, s[i], iLeft, iRight, iMaxLen);
        if ((iRight == 0) && (s[i] == '(')) continue;

        if (s[i] == '(') iLeft += 1;
        if (s[i] == ')') iRight += 1;

        if ((0 != iRight) && (iRight == iLeft))
        {
            //匹配成功
            iTmpLen = iRight * 2;
        }

        if ((0 != iRight) && (iLeft > iRight))
        {
            iRight = 0;
            iLeft = 0;
        }

        if (iMaxLen < iTmpLen) iMaxLen = iTmpLen;
    }

    return iMaxLen;
}
*/
```