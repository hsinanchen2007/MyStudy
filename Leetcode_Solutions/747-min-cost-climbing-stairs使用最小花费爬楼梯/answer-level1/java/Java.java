### 解题思路
通过题目,可以看出,你可以选择爬一个阶梯或者爬两个阶梯.所以从第一个阶梯到第三阶梯与第二个阶梯到第三个阶梯的最小值为到第三个阶梯所需的最小体力,然后,第二个阶梯到第四个阶梯与第三个阶梯到第四个阶梯的最小值作为到第四阶梯所需的最小值,依次类推,到最后的最小值就为整个爬楼梯的过程中所需要的最小值.

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {

        for(int i=2;i<cost.length;i++){
            cost[i]=Math.min(cost[i-2]+cost[i],cost[i-1]+cost[i]);
        }
        return Math.min(cost[cost.length-2],cost[cost.length-1]);
    }
}
```