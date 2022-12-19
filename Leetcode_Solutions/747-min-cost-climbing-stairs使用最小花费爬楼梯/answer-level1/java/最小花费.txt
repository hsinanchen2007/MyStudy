### 解题思路
     子问题，到第i层楼梯最少需要的体力花费
     分两种状态，在第i层可以选择（1）爬（2）跳过，总花费为costOne[i]，costTwo[i]
     从第i层到第i-1层的情况：
     第i-1层爬 ：则第i层可以选择（1）爬：总花费为costOne[i-1]+cost[i] (2)不爬：costOne[i-1]
     第i-1层不爬：则第i层必须要爬：总花费为costTwo[i-1]+cost[i]
     比较两种要爬的情况，选择最小的作为当前层的选择，

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        
        if (cost == null || cost.length < 2) {
            return 0;
        }
        int costOne = cost[0];
        int costTwo = 0;
        for (int i=1;i<cost.length;i++) {
            int temp = costTwo;
            costTwo = costOne;
            costOne = Math.min(costOne + cost[i], temp + cost[i]);
        }
        return Math.min(costOne, costTwo);
    }
    
}
```