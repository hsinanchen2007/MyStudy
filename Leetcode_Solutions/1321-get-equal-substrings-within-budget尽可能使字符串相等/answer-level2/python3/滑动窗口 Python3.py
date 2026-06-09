**思路：**

滑动窗口法。先对每个位置 `i` 求出替换的花费，用 `costs[i]` 表示。然后从左向右开始逐步增加窗口宽度，累加 `costs[i]`，并不断更新答案。当 `costs[i]` 累加值 `c ` 超过 `maxCost` 时，将窗口左端 `start` 右移，直到再次满足累加值 `c` 小于等于 `maxCost`，更新答案，并继续扩展窗口右端。如此往复，直到右端点遍历完整个 `costs` 数组。

**图解：**

![图解](https://pic.leetcode-cn.com/bea0e0596aa9ee9ac0f2881a8859b9898efa25dbdb8ed0e8a909bd241553245c.gif)

**代码：**

```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        costs = [0] * n
        for i in range(n):
            costs[i] = abs(ord(s[i]) - ord(t[i]))
        start, c, ans = -1, 0, 0
        for i in range(n):
            c += costs[i]
            while start < i and c > maxCost:
                start += 1
                c -= costs[start]
            ans = max(ans, i - start)
        return ans
```

