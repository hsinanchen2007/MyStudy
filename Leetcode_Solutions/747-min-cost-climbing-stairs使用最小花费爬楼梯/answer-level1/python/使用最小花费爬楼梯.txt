####  方法：动态规划
计算花费 `f[i]` 有一个清楚的递归关系：`f[i] = cost[i] + min(f[i+1], f[i+2])`。我们可以使用动态规划来实现。

**算法：**
- 当我们要计算 `f[i]` 时，要先计算出 `f[i+1]` 和 `f[i+2]`。所以我们应该从后往前计算 `f`。
- 在第 `i` 步，让 `f1，f2` 为 `f[i+1]`，`f[i+2]` 的旧值，并将其更新为`f[i]`，`f[i+1]` 的新值。当我们从后遍历 `i` 时，我们会保持这些更新。在最后答案是 `min(f1, f2)`。

```Python [ ]
class Solution(object):
    def minCostClimbingStairs(self, cost):
        f1 = f2 = 0
        for x in reversed(cost):
            f1, f2 = x + min(f1, f2), f1
        return min(f1, f2)
```


```Java [ ]
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int f1 = 0, f2 = 0;
        for (int i = cost.length - 1; i >= 0; --i) {
            int f0 = cost[i] + Math.min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        return Math.min(f1, f2);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 指的是 `cost` 的长度
* 空间复杂度：$O(1)$，只使用了 `f1, f2`。