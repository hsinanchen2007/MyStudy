## 思路:

从`i`到`j`位置,有 `sum(gas) < sum(cost)`,说明`i`到不了`j`,并且`i`到`j`之间任何一个位置都到不了`j`

证明可以看[官方题解](https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode)

```python []
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):return -1
        res = 0
        tank = 0
        for i, item in enumerate(zip(gas, cost)):
            tank += (item[0] - item[1])
            if tank < 0:
                res = i + 1
                tank = 0
        return res
```



```java []
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum = 0;
        for (int i = 0; i < gas.length; i++) sum += (gas[i] - cost[i]);
        if (sum < 0) return -1;
        int tank = 0;
        int res = 0;
        for (int i = 0; i < gas.length; i++) {
            tank += (gas[i] - cost[i]);
            if (tank < 0) {
                res = i + 1;
                tank = 0;
            }
        }
        return res;
    }
}
```