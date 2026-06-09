```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        for (int i = cost.length-3; i>=0 ; i--) {
            cost[i]=cost[i]+Math.min(cost[i+1],cost[i+2]);
        }
        return Math.min(cost[0],cost[1]);    
    }
}
```
思路是从后往前遍历，把每一步需要的花费改成从这一步到结束需要的花费总和，欧了


