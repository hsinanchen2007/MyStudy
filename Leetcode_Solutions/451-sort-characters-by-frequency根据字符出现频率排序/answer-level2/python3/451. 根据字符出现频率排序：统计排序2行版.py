![image.png](https://pic.leetcode-cn.com/4cc45cdd8f80ccda2e03752a69c0a3263d19746134f82b6a0b620d5b8fc75d7f-image.png)

就是很直接的统计，按关键字的统计值从大到小排序并合并输出。

```python []
class Solution:
    def frequencySort(self, s: str) -> str:
        ct = collections.Counter(s)
        return ''.join([c * t for c, t in sorted(ct.items(), key = lambda x: -x[1])])
```