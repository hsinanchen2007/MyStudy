### 解题思路
方法一：参照题解，正反两次遍历找出最大值

### 代码

```c
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
```