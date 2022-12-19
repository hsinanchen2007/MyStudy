### 解题思路
此处撰写解题思路
 到达目的地，minCosts表示到达之前行走的消耗值，只需要计算到达下一个值之前的消耗值就能计算初当前值最小值
 比如到达2之前行走是1,0的最小值，如果要计算出到达2的消耗值，只需要计算到达3之前最小值即可
### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] minCosts=new int[cost.length+1];
        minCosts[0]=0;
        minCosts[1]=0;
        for (int i = 2; i <= cost.length; i++) {
            //到达目的地，minCosts表示到达之前行走的消耗值，只需要计算到达下一个值之前的消耗值就能计算初当前值最小值
            // 比如到达2之前行走是1,0的最小值，如果要计算出到达2的消耗值，只需要计算到达3之前最小值即可
            minCosts[i]=Math.min(minCosts[i-1]+cost[i-1],minCosts[i-2]+cost[i-2]);
        }
        return minCosts[cost.length];
    }
}
```