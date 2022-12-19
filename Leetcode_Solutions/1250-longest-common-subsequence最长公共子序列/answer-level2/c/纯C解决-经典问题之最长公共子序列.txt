### 解题思路
该有的动态规划的解释在代码中都已经很清楚的标明了。


### 代码

```c
int longestCommonSubsequence(char * text1, char * text2){
    int length1=strlen(text1),length2=strlen(text2);
    
    //辅助二维数组
    int i,j;
    int dp[length1+1][length2+1];//dp[i][j]代表text1的前i个字符和text2前j个字符两者最长公共子序列

    //初始化
    for(i=0;i<=length1;i++)
    dp[i][0]=0;
    for(j=0;j<=length2;j++)
    dp[0][j]=0;

    for(i=0;i<length1;i++)
        for(j=0;j<length2;j++)//状态转移方程
        {
            if(text1[i]==text2[j])//两者相等
            dp[i+1][j+1]=dp[i][j]+1;
            else
            dp[i+1][j+1]=dp[i+1][j]>dp[i][j+1]?dp[i+1][j]:dp[i][j+1];
        }
    return dp[length1][length2];
}
```