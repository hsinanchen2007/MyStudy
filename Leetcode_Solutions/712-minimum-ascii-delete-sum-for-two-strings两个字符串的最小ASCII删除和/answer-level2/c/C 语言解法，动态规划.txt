### 解题思路
 	// 计算两个字符串的ASCII总和
 	// 找出最长的公共子序列,计算其 ASCLL 总和，再相减即可

### 代码

```c
int MAX(int a,int b){return a>b?a:b;}
int minimumDeleteSum(char * s1, char * s2){

	int dp[1001][1001];

 	int len1 = strlen(s1);
 	int len2 = strlen(s2);

 	int cnt1 = 0,cnt2=0;
 	// 计算两个字符串的ASCII总和
 	for (int i = 0; i < len1; ++i) cnt1 += s1[i];
 	for (int i = 0; i < len2; ++i) cnt2 += s2[i];
 	// 找出最长的公共子序列
 	// 与公共子序列的 ASCLL 总和，相减即可
 	int cnt3=0;
 	// dp 初始化
 	for (int i = 0; i <= len1; ++i) dp[i][0] = 0;
 	for (int i = 0; i <= len2; ++i)	dp[0][i] = 0;
 	for (int i = 1; i <= len1; ++i)
 	{
 		for (int j = 1; j <= len2; ++j)
 		{
            //状态转移方程
 			if (s1[i-1] == s2[j-1])
 			    dp[i][j] = dp[i-1][j-1]+s1[i-1]; 
 			else
 				dp[i][j] = MAX(dp[i-1][j],dp[i][j-1]);
 		}
 	}
    int res= cnt1+cnt2-dp[len1][len2]*2;
 	return res;
}
```