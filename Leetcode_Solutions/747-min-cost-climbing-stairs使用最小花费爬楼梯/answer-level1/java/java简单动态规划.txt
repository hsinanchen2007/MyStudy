简单动态规划，每一步应该加上（前一步或者前两步）的最小值
```
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int len = cost.length;
        int[] new_cost = new int[len+1];
        System.arraycopy(cost,0,new_cost,0,len);
        for (int i = 2; i < len+1; i++) {
            new_cost[i] += Math.min(new_cost[i-1],new_cost[i-2]);
        }
        return new_cost[len];
    }
}
```
