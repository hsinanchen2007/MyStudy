#### 方法一：单次扫描

我们只需要对数组进行一次扫描就可以计算出总的中毒持续时间。

考虑相邻两个攻击时间点 `A[i]` 和 `A[i + 1]` 以及中毒持续时间 `t`，如果 `A[i] + t <= A[i + 1]`，那么在第 `i + 1` 次攻击时，第 `i` 次攻击造成的中毒的持续时间已经结束，即持续时间为 `t`；如果 `A[i] + t > A[i + 1]`，那么在第 `i + 1` 次攻击时，第 `i` 次攻击的中毒仍然在持续，由于中毒状态不可叠加，因此持续时间为 `A[i + 1] - A[i]`。

![pic](https://pic.leetcode-cn.com/Figures/495/ashe.png){:width=500}

```Java [sol1]
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int n = timeSeries.length;
        if (n == 0) return 0;

        int total = 0;
        for(int i = 0; i < n - 1; ++i)
          total += Math.min(timeSeries[i + 1] - timeSeries[i], duration);
        return total + duration;
    }
}
```

```Python [sol1]
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        if n == 0:
            return 0
        
        total = 0
        for i in range(n - 1):
            total += min(timeSeries[i + 1] - timeSeries[i], duration)
        return total + duration
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(1)$。