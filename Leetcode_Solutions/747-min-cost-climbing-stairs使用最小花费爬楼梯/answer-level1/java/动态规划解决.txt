### 解题思路
/*
到达某个点有两种方式，一种是经过这个点，另一种是跳过这个点；
使用动态规划，建造两个dp数组分别存储上述两个状态的最小花费：dp0，dp1；
那么就可以得到递推关系式：dp0[i]=dp1[i-1];dp1[i]=min(dp1[i-1],dp0[i-1])+cost[i].
最后输出min(dp0[n-1],dp1[n-1])
*/

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp0 = new int[n];
        int[] dp1 = new int[n];
        dp0[0] = 0;
        dp1[0] = cost[0];
        for(int i=1;i<n;i++){
            dp0[i] = dp1[i-1];
            dp1[i] = Math.min(dp1[i-1],dp0[i-1])+cost[i];
        }
        return Math.min(dp0[n-1],dp1[n-1]);
    }
}
```