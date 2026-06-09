一、解题思路
    dp[i][j]表示S[0~i]包含的T[0~j]的个数。当S[i]==T[j]时，dp[i][j]=dp[i-1][j]+dp[i-1][j-1]。dp[i-1][j]表示S[0~i-1]包含的T[0~j]的个数，dp[i-1][j-1]表示S[0~i-1]包含的T[0~j-1]的个数。前者的意思是，不管S[i]是什么，至少知道S[0~i-1]包含的T[0~j]的个数。后者的意思是，当加入S[i]和T[j]，且S[i]==T[j]时，这时候S[0~i]就刚好包含T[0~j]，包含的个数，取决于S[0~i-1]包含多少个T[0~j-1]。
    在S和T前面随意加一个字符，当i==0或j==0时，表示空串。试想如果T为空，无论S为什么，都包含一个T，即包含一个空串。所以要初始化dp[0~S1.length][0]=1。

二、代码
```
class Solution {			
	 public int numDistinct(String s, String t) {
		 s = ' ' + s;
		 int n = s.length();
		 t = ' ' + t;
		 int m = t.length();
		 
		 int[][] dp = new int[n][];
		 for(int i = 0; i < n; i++)
			 dp[i] = new int[m];
		 for(int i = 0; i < n; i++)
			 dp[i][0] = 1;
		 
		 for(int i = 1; i < n; i++) {
			 for(int j = 1; j < m; j++) {
				 dp[i][j] = dp[i-1][j] + (s.charAt(i) == t.charAt(j) ? dp[i-1][j-1] : 0);
			 }
		 }
		 
		 return dp[n-1][m-1];
	 }

}
```
