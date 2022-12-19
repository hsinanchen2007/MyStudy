### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n <= 1)
			return n;
		
		//dp[i]表示 爬到i级台阶有几种不同的方法
		int[] dp = new int[n+1];
		
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
    }
}
```
![image.png](https://pic.leetcode-cn.com/bbc64590b8b43c1d3426dd0344d1dee283a2695a6b5bdc3bd680919c30e197bd-image.png)
