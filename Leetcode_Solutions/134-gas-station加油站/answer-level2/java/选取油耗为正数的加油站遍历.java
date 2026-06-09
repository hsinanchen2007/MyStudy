### 解题思路
详细的题解请参考代码和注释，已经写的非常清楚了。

### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        // 计算环路总油量
        int totalGas = Arrays.stream(gas).sum();
        int totalCost = Arrays.stream(cost).sum();
        // 总油量不够花费的肯定是不行的
        if (totalCost > totalGas) {
            return -1;
        }
        // 选取油耗为正数的加油站
        // 只有这样的加油站才可能作为起点
        List<Integer> stations = new LinkedList<>();
        for (int i = 0; i < gas.length; i++) {
            int t = gas[i] - cost[i];
            if (t >= 0) {
                stations.add(i);
            }
        }
        // 开始遍历加油站
        for (int start : stations) {
            int end = -1;
            // 计算出当前环路的结尾脚标
            // 如果当前脚标是在0
            // 那么结尾就是最后一个元素
            if (start == 0) {
                end = gas.length;
            }
            // 如果当前脚标不是第一个元素
            // 那么结尾就会循环到这个元素前面1个
            if (start > 0) {
                end = start - 1;
            }
            // 定义剩余油量
            int left = 0;
            for (int i = start; i != end; ) {
                // 计算剩余油量
                left += gas[i] - cost[i];
                // 剩余油量不够直接计算下一个
                if (left < 0) {
                    // 开始下一轮
                    break;
                }
                // 定义往哪儿开
                if (i < end) {
                    i++;
                } else if (i > end) {
                    // 跑到最后一个元素了
                    // 重置，从第0个开始继续跑
                    if (i == gas.length - 1) {
                        i = 0;
                    } else {
                        i++;
                    }
                }
            }
            // 跑完全程如果油量油剩余就肯定可以跑完
            if (left >= 0) {
                return start;
            }
        }
        return -1;
    }
}
```