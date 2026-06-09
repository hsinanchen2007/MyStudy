### 解题思路
方法一：动态规划法, 时间超时
1,创建动态数组dp保存中间结果
2,if p[j]=a-z  
      if p[j] == s[i]  p[i][j] = p[i-1][j-1]
3,if p[j]='?' p[i][j] = p[i-1][j-1]
4,if p[j]='*' p[i][j] = p[i-1][j] | p[i-1][j-1] | p[i-1][j]  (*分别表示空，当前字符，任意字符串)
优化一：当p中某个字符在 s 中一次都匹配不上，则直接返回 false;

### 代码

```c
//方法一：动态规划法, 时间超时
//1,创建动态数组dp保存中间结果
//2,if p[j]=a-z  
//      if p[j] == s[i]  p[i][j] = p[i-1][j-1]
//3,if p[j]='?' p[i][j] = p[i-1][j-1]
//4,if p[j]='*' p[i][j] = p[i-1][j] | p[i-1][j-1] | p[i-1][j]  (*分别表示空，当前字符，任意字符串)
//优化一：当p中某个字符在 s 中一次都匹配不上，则直接返回 false;
bool isMatch(char * s, char * p){
    int     i           = 0;
    int     j           = 0;
    int     iSlen       = strlen(s);
    int     iPlen       = strlen(p);
    bool    dp[5000][5000] = {0};
    bool    bTmp        = false;

    if ((iSlen == 0) && (iPlen == 0)) return true;


    //1,初始化 dp 数组
    dp[0][0] = true;

    for (j = 0; j < iPlen; j++)
    {
        bTmp = false;
        if (p[j] == '*')
        {
            dp[0][j + 1] = dp[0][j];
            if (dp[0][j + 1]) bTmp = true;
        }

        for (i = 0; i < iSlen; i++)
        {
            if (p[j] == '?')
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else if (p[j] == '*')
            {
                dp[i + 1][j + 1] = dp[i][j + 1] | dp[i][j] | dp[i + 1][j];
            }
            else
            {
                if (p[j] == s[i])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
            
            if (dp[i + 1][j + 1]) bTmp = true;
        }
        if (!bTmp) return false;
    }
    return dp[iSlen][iPlen];
}
```