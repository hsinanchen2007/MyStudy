####  方法：动态规划 [Accepted]
- 因为是正整数，所以我们取其中一个元素来得分，我们也可以取与它相同的元素来得分，因为我们已经删除了它的所有的邻居数字。我们可以计算出每个数字值多少点数。
- 当我们添加一个新的数字 `X`（包括副本）时会发生什么？如果这个数字比 `nums` 的数字都大。那么我们可以获得的点数是 `nums` 可以获得的点数再加上 `X` 的值——这可以用动态规划来解决。但是，如果我们 `nums` 中有数字是 `X` 的邻居，那么就会出现问题。
- `using` 指的是先前能够获得的点数，`avoid` 指的是不使用先前最大值 `prev` 能够获得的点数。

**算法：**
- 对于 `nums` 中的点数 `k`，我们记录正确的 `avoid` 和 `using`，分别了代表不获取点数 `k` 和获取点数 `k` 的情况。
- 若新值 `k` 与先前的最大值 `pre` 相邻，则获得点数 `k`，我们的答案为 `(k 的总点数) + avoid`；删除点数 `k`，答案为 `max(avoid, using)`。同样的，如果 `k` 和 `prev` 不相邻，则获得点数 `k` 的答案为 `(k 的总点数) + max(avoid, using)`；删除点数 `k` 答案为 `max(avoid, using)`
- 最后，最佳答案可能使用或不使用 `nums` 中的最大值，因此我们返回 `max(avoid, using)`

```Python [ ]
class Solution(object):
    def deleteAndEarn(self, nums):
        count = collections.Counter(nums)
        prev = None
        avoid = using = 0
        for k in sorted(count):
            if k - 1 != prev:
                avoid, using = max(avoid, using), k * count[k] + max(avoid, using)
            else:
                avoid, using = max(avoid, using), k * count[k] + avoid
            prev = k
        return max(avoid, using)
```

```Java [ ]
class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] count = new int[10001];
        for (int x: nums) count[x]++;
        int avoid = 0, using = 0, prev = -1;

        for (int k = 0; k <= 10000; ++k) if (count[k] > 0) {
            int m = Math.max(avoid, using);
            if (k - 1 != prev) {
                using = k * count[k] + m;
                avoid = m;
            } else {
                using = k * count[k] + avoid;
                avoid = m;
            }
            prev = k;
        }
        return Math.max(avoid, using);
    }
}
```

**复杂度分析**

* 时间复杂度 (Python)：$O(N \log N)$。其中  $N$ 指的是 `nums` 的长度。复杂度依赖于排序算法。
* 空间复杂度 (Python)：$O(N)$，`count` 所使用的空间。
* 时间复杂度 (Java)：由于使用了基数排序，所以我们的复杂度是 $O(N+W)$，其中 $W$ 是 `nums[i]` 的可取值的范围。
* 空间复杂度 (Java)：$O(W)$，`count` 所使用的空间。