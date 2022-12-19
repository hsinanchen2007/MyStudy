![image.png](https://pic.leetcode-cn.com/a433f4a97ca9875960b3ee7115bfce40dc7185e8ec8dc3d9b59acdc9c13e3896-image.png)

顺着大佬的思路写的一个Python版，因为串中顺序可以重新排列，所以统计各个串中频次为奇数的字母个数就成了关键，统计出来后再和串长度的奇偶性和两倍的`k`作比较，就可以确认该串是否需要修改了，根据这个原理可以知道，`t`最大也就是`26`，当`k >= 13`的时候，必然符合检测，所以预处全`True`后只用计算`k < 13`的情况就行了。

1100ms，时间仅供参考。

```python []
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        ans = [True] * len(queries)
        for i, (l, r, k) in enumerate(queries):
            if k < 13:
                d = collections.Counter(s[l: r + 1])
                t = len([0 for ct in d.values() if ct % 2])
                ans[i] = t <= 2 * k + (r + 1 - l) % 2
        return ans
```
