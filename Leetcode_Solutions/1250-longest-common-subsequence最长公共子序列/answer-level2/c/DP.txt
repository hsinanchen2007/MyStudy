### 解题思路
DP法
1. dalao说过几乎所有的字符串问题都可以用DP法做，并且几乎都是二维DP，那就建个二维DP数组
2. 找DP数组含义，dp[i][j]表示字符串切片text1[0:i],text2[0:j]里面最长的公共子序列，
3. 找状态转移方程，如果text[i]==text[j]那么表明一样的字符又多了一个 dp[i][j]=dp[i-1]+dp[j-1]+1
   如果不等，那么就取上下最大的 dp[i][j] = max(dp[i-1][j],dp[i][j-1])
4. 返回dp最后一个点即可

### 代码

```c
int longestCommonSubsequence(char * text1, char * text2){
    int len1=strlen(text1),len2=strlen(text2),**dp;
    dp = (int**)malloc(sizeof(int*)*(len1+1));
    for (int i=0;i<len1+1;i++)
        dp[i] = (int*)malloc(sizeof(int)*(len2+1));
    for (int i=0;i<len1+1;i++)
        dp[i][0] = 0;
    for (int i=0;i<len2+1;i++)
        dp[0][i] = 0;
    for (int i=1;i<len1+1;i++){
        for (int j=1;j<len2+1;j++){
            if (text1[i-1]==text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                if (dp[i-1][j]>dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[len1][len2];
}

```