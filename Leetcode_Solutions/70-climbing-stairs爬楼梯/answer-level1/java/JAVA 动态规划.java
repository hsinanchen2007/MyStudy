### 解题思路
动态规划方法
先找规律：eg：1->1,2->2,3->3,4->5,5->8; 找出如果上n(n>2)高的楼，需要的步骤为爬上n-1台阶加上n-2台阶的和。
则用dp数组存放，dp[i] = dp[i-1]+dp[i-2];
最后返回dp[n-1],因为数组索引是从0开始的，0代表1层高的楼

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int[] dp = new int[10000];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n-1];
    }
}
```