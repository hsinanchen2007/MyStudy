根据题目，初始条件为cost[0]和cost[1];则到2的最小花费就是0和1中小的花费加上2本身，由此可以推出状态转移方程
```
cost[n]= Math.min(cost[n - 1], cost[n - 2]);
```

```java
public int minCostClimbingStairs(int[] cost) {
    int n = cost.length;
    for (int i = 2; i < n; i++) {
        cost[i] += Math.min(cost[i - 1], cost[i - 2]);
    }
    return Math.min(cost[n - 1], cost[n - 2]);
}
```
时间复杂度O（N）:取决于数组长度
空间复杂度：只用数组本身
