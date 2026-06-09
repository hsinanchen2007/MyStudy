### 解题思路
此处撰写解题思路
还是不熟练啊
### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n <= 1)
			return n;
		
		//dp[i]表示 爬到i级台阶有几种不同的方法 
		//0级台阶dp[0]、1级台阶...3级台阶dp[3]
		int[] dp = new int[n+1];
		
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
}}
```
![image.png](https://pic.leetcode-cn.com/a1229c52f429fa58bb84e072c786b79c5a1ecea434f3b6a1e74ab59347f7fe76-image.png)
