### 解题思路
动态规划
思路，如果可以绕行一周，到达每个站的剩余汽油不小于0
以示例1，假设第一站出发，我们记录到达每个站所剩油量
[0，-2，-4，-6，-3, 0]
如果可以绕行，最后一站的剩余油量必须不小于0.
那么怎么确定从那一站出发呢？
每一站都能到，最小值那一站也能到，找出最小值的下一站
### 代码

```c

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int *dp = (int*)malloc(sizeof(int) * gasSize);
    if (!dp) {
        return -1;
    }
    dp[0] = gas[0] - cost[0];
    int min = dp[0];
    int minIndex = 0;
    for (int i = 1; i < gasSize; i++) {
        dp[i] = dp[i-1] + gas[i] - cost[i];
        if (min > dp[i]) {
            min = dp[i];
            minIndex = i;
        }
    }
    if (dp[gasSize - 1] >= 0) {
        return (minIndex + 1) % gasSize;
    } else {
        return -1;
    }    
}
```