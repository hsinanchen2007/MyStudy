### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户.
一个滚动数组即可解决
### 代码

```java
class Solution {
    public int climbStairs(int n) {
        int[] dp = {0,0,1};
    	for(int i=0;i<n;i++) {
			dp[0] = dp[1];
			dp[1] = dp[2];
			dp[2] = dp[0] + dp[1];
		}
    	return dp[2];
    }
}
```
