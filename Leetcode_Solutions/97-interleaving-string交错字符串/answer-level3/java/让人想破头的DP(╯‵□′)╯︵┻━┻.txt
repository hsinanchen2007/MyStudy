一、解题思路
    dp[i][j]表示s1[0~i]和s2[0~j]能串成的s3的长度，例如s1="ab"，s2="ef"，s3="aebf"，则dp[1][0]=3，即"ab"和"e"能串成"abe"。
    为了适应我的状态转移方程，在s1和s2前面各加一个字符，例如" "，加这个字符的目的只是让s1和s2的第一个有效字符下标为1。
    求解过程。对于s3中下标为k的字符（s3[k]长度len为4），求解所有可能的i和j，使得dp[i][j]=k。例如，当k=3时，i和j的组合有(0, 4)、(1, 3)、(2, 2)、(3, 1)。(0, 4)表示s3[0~3]由s2[1~4]组成。因为i和j的关系用j=len-i表示，所以这时候就能知道s1和s2前面加一个字符的作用，就是防止越界。接下来分析，当s1[i]==s3[k]时，如果dp[i-1][j]==k-1，即如果dp[i-1][j]能串到s3中下标为k的字符的前一个字符，则s1[i]和s2[j]能串到s3的下标为k的字符。或者当s2[j]==s3[k]时，如果dp[i][j-1]==k-1，即如果dp[i-1][j]能串到s3中下标为k的字符的前一个字符，则s1[i]和s2[j]能串到s3的下标为k的字符。
    一直重复以上过程，知道对于s3的最后一个字符，求解所有可能的i和j，求解所有可能的i和j，使得dp[i][j]=s3的长度。如果dp[s1的长度-1][s2的长度-1]==s3的长度，说明s1和s2可以串成s3。
    感觉有点复杂，很难表达清楚，自己也是想了很久才迷迷糊糊想出来的。

二、代码（Java实现）
```
class Solution {			
	public boolean isInterleave(String s1, String s2, String s3) {
		if(s1.length() + s2.length() != s3.length())
			return false;
		if(s1.length() == 0)
			return s2.equals(s3);
		if(s2.length() == 0)
			return s1.equals(s3);
		if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
			return true;
		
		s1 = " " + s1;
		s2 = " " + s2;
		
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		char[] c3 = s3.toCharArray();
		
		int n = c1.length, m = c2.length, l = c3.length;
		
		int[][] dp = new int[n][];
		for(int i = 0; i < n; i++)
			dp[i] = new int[m];
		
		for(int len = 1; len <= l; len++) {
			char target = c3[len-1];
			for(int x = 0; x <= len && x < n; x++) {
				int y = Math.min(len-x, m-1);
				if(c2[y] == target && dp[x][y-1] == len - 1) {
					dp[x][y] = dp[x][y-1] + 1;
				} else if(c1[x] == target && dp[x-1][y] == len - 1) {
					dp[x][y] = dp[x-1][y] + 1;
 				}
			}
		}
		
		return dp[n-1][m-1] == s3.length() ? true: false;
    }

}
```
