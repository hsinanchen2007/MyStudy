### 解题思路
参考自 <https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/shi-yong-zui-xiao-hua-fei-pa-lou-ti-by-leetcode/>

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int f1 =0;
        int f2 =0;
        for(int i = cost.length - 1 ;i >= 0;i--){
            int f0 = cost[i] + Math.min(f1,f2);
            f2 = f1;
            f1 = f0;
        }
        return Math.min(f1,f2);
    }
}
```