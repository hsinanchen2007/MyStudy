最长公共子序列是二维动态规划里面非常经典的一道题。

目的是求出A,B两个字符串中的最长公共子序列。

A的长度若为M，B的长度若为N，那么A就有2的M次方的子序列，B就有2的N次方的子序列。可得枚举方法下的时间复杂

度就是两者的乘积。往往遇到递归和枚举的复杂度非常高，可以考虑一下动态规划。

Am和Bn的最长公共子序列从后往前有这样的关系。

若A[i]=B[j]，那么LCS(Ai,Bj)=LCS(Ai-1,Bj-1)+1;

反之，A[i]!=B[j],那么LCS(Ai,Bj)=max(LCS(Ai-1,Bj),LCS(Ai,Bj-1));

个人觉得最关键的是为什么这里要考虑用二维数组来记录。

因为LCS(Ai,Bj)是来自于LCS(Ai-1,Bj-1)、LCS(Ai-1,Bj)、LCS(Ai,Bj-1)三者中的其中一个。

恰好构成了一个正方形的规则。

二维数组恰好也能够满足这一点。

PS：其实我觉得我写的并没有其他大佬的好，因为排版并不太好，我只是通过写题解的方式来加深自己的学习印象。

不喜勿喷。。。

附上C语言的代码。

```
int longestCommonSubsequence(char * text1, char * text2){
    int length1=strlen(text1),length2=strlen(text2);
    int dp[length1+1][length2+1],i,j;
    for(i=0;i<=length1;i++)//初始化边界条件
        dp[i][0]=0;
    for(i=0;i<=length2;i++)
        dp[0][i]=0;
    for(i=1;i<length1+1;i++)
        for(j=1;j<length2+1;j++)
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j];
            }
    return dp[i-1][j-1];
}
```

