#### 方法一：贪心

首先，显然只有当 `N` 台洗衣机的衣服数量之和 `D` 是 `N` 的倍数时，才能使得每台洗衣机最终的衣服数量相等。

![bla](https://pic.leetcode-cn.com/Figures/517/could_solve2.png){:width=400}

当计算出 `D` 之后，我们可以通过 `D / N` 得到每台洗衣机最终的衣服数量。

![bla](https://pic.leetcode-cn.com/Figures/517/distribution.png){:width=400}

为了方便计算，我们可以将所有的 `N` 个数分别减去 `D / N`，这样若第 `i` 台洗衣机对应的数为正数，说明它需要拿出衣服分给别的洗衣机；若第 `i` 台洗衣机对应的数为负数，说明它需要从别的洗衣机得到衣服。

![bla](https://pic.leetcode-cn.com/Figures/517/to_be_removed.png){:width=400}

由于每一步操作中一台洗衣机只能给出一件衣服，因此如果其中一台洗衣机对应的数为正数 `x`，那么操作步数至少为 `x`。并且对于前 `i` 台洗衣机，它们对应的数的和若为 `y`，那么它们需要和后 `N - i` 台洗衣机至少传递 `|y|` 次衣服，每次只能传递一件（若 `y` 为正数，则前者将衣服传递给后者；若 `y` 为负数，则后者将衣服传递给前者），操作步数至少为 `y`。因此，最少的操作步数为“数组元素的最大值”和“数组元素前缀和的绝对值的最大值”中的较大值。

我们从左到右扫描数组，并求出以下三个值：

- `m`：当前位置的数值；

- `curr_sum`：到当前位置为止的前缀和；

- `max_sum`：到当前位置为止的前缀和的绝对值的最大值。

通过这三个值，我们就能求出最少的操作步数。下面给出了三个例子：

- `[1, 0, 5]`，“数组元素的最大值” 和 “数组元素前缀和的绝对值的最大值” 相等：

![bla](https://pic.leetcode-cn.com/Figures/517/table1.png){:width=400}

- `[0, 3, 0]`，“数组元素的最大值” 为较大值：

![bla](https://pic.leetcode-cn.com/Figures/517/table2.png){:width=400}

- `[0, 0, 3, 5]`，“数组元素前缀和的绝对值的最大值” 为较大值：

![bla](https://pic.leetcode-cn.com/Figures/517/table3.png){:width=400}

```Python [sol1]
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        dress_total = sum(machines)
        if dress_total % n != 0:
            return -1
        
        dress_per_machine = dress_total // n
        for i in range(n):
            # Change the number of dresses in the machines to
            # the number of dresses to be removed from this machine
            # (could be negative)
            machines[i] -= dress_per_machine
            
        # curr_sum is a number of dresses to move at this point, 
        # max_sum is a max number of dresses to move at this point or before,
        # m is number of dresses to move out from the current machine.
        curr_sum = max_sum = res = 0
        for m in machines:
            curr_sum += m
            max_sum = max(max_sum, abs(curr_sum))
            res = max(res, max_sum, m)
        return res
```

```Java [sol1]
class Solution {
    public int findMinMoves(int[] machines) {
        int n = machines.length, dressTotal = 0;
        for (int m : machines) dressTotal += m;
        if (dressTotal % n != 0) return -1;

        int dressPerMachine = dressTotal / n;
        // Change the number of dresses in the machines to
        // the number of dresses to be removed from this machine
        // (could be negative)
        for (int i = 0; i < n; i++) machines[i] -= dressPerMachine;

        // currSum is a number of dresses to move at this point, 
        // maxSum is a max number of dresses to move at this point or before,
        // m is number of dresses to move out from the current machine.
        int currSum = 0, maxSum = 0, tmpRes = 0, res = 0;
        for (int m : machines) {
            currSum += m;
            maxSum = Math.max(maxSum, Math.abs(currSum));
            tmpRes = Math.max(maxSum, m);
            res = Math.max(res, tmpRes);
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。
 
* 空间复杂度：$O(1)$。