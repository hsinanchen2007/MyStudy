### 解题思路
用动态规划做的，总算完成了。。。略显鸡肋，也可以学习。
如果s(i)==t(j) -> dp[i][j] = dp[i-1][j-1]+1
如果s(i)!=t(j) -> dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1])
为什么这里写死了数组行数，因为实际参与计算的只有两层，这样可以优化空间。不至于到m x n
计算次数i%2则代表该行数据应该放在第几行和应该读取哪一行数据。
可以供大家学学状态转移方程推导。
### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
		int dp[][] = new int[3][t.length()+1] ;
		for(int i=1;i<s.length()+1;i++) {
			for(int j=1;j<dp[0].length;j++) {
				if(i%2==1) {
					if(s.charAt(i-1)==t.charAt(j-1)) 
					{
						dp[2][j] = dp[1][j-1]+1 ;
					}
					else
					{
						dp[2][j] = Math.max(dp[1][j],dp[2][j-1]) ;
					}
				}else {
					if(s.charAt(i-1)==t.charAt(j-1)) 
					{
						dp[1][j] = dp[2][j-1]+1 ;
					}
					else
					{
						dp[1][j] = Math.max(dp[2][j],dp[1][j-1]) ;
					}
				}
			}
		}
		if(s.length()%2==1) {
			return s.length() == dp[2][t.length()] ;
		}
		return s.length() == dp[1][t.length()] ;
    }
}
```