#### 方法一：计数【通过】

**思想**

根据以下步骤推导出解决方案：

其实我们只关心数组中的元素是否小于 `L`，大于 `R`，或者位于 `[L, R]` 之间。假设一个元素小于 `L` 标记为 `0`，位于 `[L, R]` 之间标记为 `1`，大于 `R` 标记为 `2`。

我们希望找出不包含 `2` 且至少包含一个 `1` 的子数组数量。因此可以看作是所有的 `2` 将数组拆分为仅包含 `0` 或 `1` 的子数组。例如在数组 `[0, 0, 1, 2, 2, 1, 0, 2, 0]`，`2` 将数组拆分为 `[0, 0, 1]`、`[1, 0]` 和 `[0]` 三个子数组。 

接下来，需要计算每个只包含 `0` 或 `1` 的数组中，至少包含一个 `1` 的子数组数量。那么问题可以转换为先找出所有的子数组，再从中减去只包含 `0` 的子数组。

例如，`[0, 0, 1]` 有 6 个子数组，其中 3 个子数组只包含 `0`，3 个子数组至少包含一个 `1`；`[1, 0]` 有 3 个子数组，其中 1 个子数组只包含 `0`，2 个子数组至少包含一个 `1`；`[0]` 只有 1 个子数组，且这个子数组只包含 `0`。因此数组 `A = [0, 0, 1, 2, 2, 1, 0, 2, 0]` 中不包含 `2`，且至少包含一个 `1` 的子数组的数量是 `3 + 2 + 0 = 5`。

**算法**

假设 `count(B)` 用于计算所有元素都小于等于 `B` 的子数组数量。根据上面分析，本题答案为 `count(R) - count(L-1)`。

那么如何计算 `count(B)`？使用 `cur` 记录在 `B` 的左边，小于等于 `B` 的连续元素数量。当找到一个这样的元素时，在此位置上结束的有效子数组的数量为 `cur + 1`。当遇到一个元素大于 `B` 时，则在此位置结束的有效子数组的数量为 0。

```java [solution1-Java]
class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        return count(A, R) - count(A, L-1);
    }

    public int count(int[] A, int bound) {
        int ans = 0, cur = 0;
        for (int x: A) {
            cur = x <= bound ? cur + 1 : 0;
            ans += cur;
        }
        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        def count(bound):
            ans = cur = 0
            for x in A :
                cur = cur + 1 if x <= bound else 0
                ans += cur
            return ans

        return count(R) - count(L - 1)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 `N` 是 `A` 的长度。

* 空间复杂度：$O(1)$。