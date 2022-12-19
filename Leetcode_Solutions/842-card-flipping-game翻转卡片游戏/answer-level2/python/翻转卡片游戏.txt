#### 方法 1：Hash Set

**想法**

如果一张卡片正反两面有相同值 `x`，那么一定不能使用 `x` 这个数字。否则，就有两个不同的取值，如果选择数字 `x`，那么可以让 `x` 朝向下方。

**算法**

记住所有在一张卡上出现两次的值 `same`，然后每个不在 `same` 中的值 `x` 都是一个可能的答案。如果没有可能答案，结果就是 0。

```Java []
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet();
        for (int i = 0; i < fronts.length; ++i)
            if (fronts[i] == backs[i])
                same.add(fronts[i]);

        int ans = 9999;
        for (int x: fronts)
            if (!same.contains(x))
                ans = Math.min(ans, x);

        for (int x: backs)
            if (!same.contains(x))
                ans = Math.min(ans, x);

        return ans % 9999;
    }
}
```

```Python []
class Solution(object):
    def flipgame(self, fronts, backs):
        same = {x for i, x in enumerate(fronts) if x == backs[i]}
        ans = 9999
        for x in itertools.chain(fronts, backs):
            if x not in same:
                ans = min(ans, x)

        return ans % 9999
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `fronts`（`backs`）的长度，我们需要遍历这个数组。
* 空间复杂度：$O(N)$。