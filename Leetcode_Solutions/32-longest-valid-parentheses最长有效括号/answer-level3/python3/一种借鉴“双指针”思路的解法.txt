试想对于输入序列 `(()(()()`（易知其解为 4），若将 `(` 看作**下坡**，`)` 看作**上坡**，则可将输入字符串转化为如下 “地形”：

```text

    (()(()()
        ----

    \
     \/\
        \/\/

```

此时，问题即被转化为求上述地形中**最大 “水坑”** 的宽度，或**单向最大连续填充长度**。

假设最左处地形高度为 0，则可首先通过一次遍历求得地形最右处的高度（在之后的遍历过程中，每一点的高度都可以随遍历反推得到），再通过双指针遍历得到最大水坑的大小。

总时间复杂度来自两次遍历，最终为 $O(n)$，使用固定大小内存。

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:

        # Get sealevel of rightmost point
        right_level = 0
        for ch in s:
            if ch == '(':
                right_level -= 1
            else:
                right_level += 1

        # Walk the terrain
        pl, pr = 0, len(s)              # left / right pointers (pr is one-off-end)
        levl, levr = 0, right_level     # sealevel at left / right pointer
        maxl, maxr = 0, right_level     # maximum sealevel seen so far
        max_count = 0                   # the length to be returned
        count = 0                       # used to track size of current pool across iterations
        from_left = True                # used to track direction of growth of last pool
        while pl < pr:
            if levl < levr:
                # Advance forward
                levl += 1 if s[pl] == ')' else -1
                pl += 1
                # Judge
                if levl <= maxl:
                    if from_left:   # still in last pool
                        count += 1
                    else:           # reversing direction
                        max_count = max(max_count, count)
                        count = 1   # NOTE: initialize to 1 instead of 0, counting current cell
                else:               # walking out of current pool
                    max_count = max(max_count, count)
                    count = 0
                    maxl = levl
                from_left = True
            else:
                levr -= 1 if s[pr - 1] == ')' else -1
                pr -= 1
                if levr <= maxr:
                    if not from_left:
                        count += 1
                    else:
                        max_count = max(max_count, count)
                        count = 1
                else:
                    max_count = max(max_count, count)
                    count = 0
                    maxr = levr
                from_left = False

        # Sync last pool size to result
        max_count = max(max_count, count)

        return max_count

```

> 以上实现未经任何优化。  
> 看到解答区没有类似的解法，故写出来提供不同的思路。若有好心人发现该方法仍有优化的余地，还请在评论区留言供分享。

> 灵感来自 #42 Trap Rain Water 的双指针解法。
