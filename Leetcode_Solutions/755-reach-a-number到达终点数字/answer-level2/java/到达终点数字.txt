#### 方法一：分析 + 数学

假设我们移动了 `k` 次，每次任意地向左或向右移动，那么最终到达的位置实际上就是将 `1, 2, 3, ..., k` 这 `k` 个数添加正号（向右移动）或负号（向左移动）后求和的值。并且如果最终到达的位置为 `t` 且 `t < 0`，那么我们可以将这 `k` 个数的符号全部取反，这样求和的值为 `-t > 0`。因此我们只考虑题目中 `target > 0` 的情况。

我们沿用上面的符号，设 `k` 为最小的满足 `S = 1 + 2 + ... + k >= target` 的正整数，如果 `S == target` 那么答案显然是 `k`。如果 `S > target`，那么我们需要将一些正号变为负号，使得最后求和的值等于 `target`。当前比 `target` 多出了 `delta = S - target`，那么我们需要在 `1, 2, ..., k` 中找到若干个数变成负号，并且它们的和为 `delta / 2`。可以证明一定能找到和为 `delta / 2` 的若干个数：如果 `delta / 2 <= k`，那么只需要选出 `delta / 2` 即可；如果 `delta / 2 > k`，那么先选出 `k`，再从 `1, 2, 3, ..., k - 1` 中选出若干个数使得它们的和为 `delta / 2 - k`，这样就把原问题变成了一个规模更小的子问题。显然 `delta / 2 <= 1 + 2 + ... + k`，因此一定能选出若干个数。

上面只适用于 `delta` 为偶数的情况。若 `delta` 为奇数，则 `delta / 2` 不为整数，因此无法选出。此时我们只能考虑 `k + 1` 和 `k + 2`，求出 `1` 到 `k + 1` 的和以及 `1` 到 `k + 2` 的和，它们中必有一个和 `1` 到 `k` 的和的奇偶性不同，此时 `delta` 变为偶数，可以选出若干个数。

我们给出了四个具体的例子来解释上面的数学证明：

* 如果 `target = 3`，那么 `k = 2, delta = 0`，答案为 `k = 2`；
* 如果 `target = 4`，那么 `k = 3, delta = 2` 为偶数，答案为 `k = 3`；
* 如果 `target = 7`，那么 `k = 4, delta = 3` 为奇数，考虑 `k = 5`，`delta` 变为 `8` 为偶数，答案为 `k = 5`；
* 如果 `target = 5`，那么 `k = 3, delta = 1` 为基数，考虑 `k = 4`，`delta` 变为 `5` 仍为奇数，`k = 5`，`delta` 变为 `10` 为偶数，答案为 `k = 5`。

```Python [sol1]
class Solution(object):
    def reachNumber(self, target):
        target = abs(target)
        k = 0
        while target > 0:
            k += 1
            target -= k

        return k if target % 2 == 0 else k + 1 + k%2
```

```Java [sol1]
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int k = 0;
        while (target > 0)
            target -= ++k;
        return target % 2 == 0 ? k : k + 1 + k%2;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sqrt{\text{target}})$，从 `1` 到 `k` 求和时有 $1 + 2 + \dots + k = \frac{k(k+1)}{2}$，因此 `k` 为 `target` 的平方根级别。

* 空间复杂度：$O(1)$。