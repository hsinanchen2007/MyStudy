### 解题思路
真是烦
实在搞不懂这种case为什么是：-1

3
[1, 0, 0, 1]

没办法只能削足适履了...

### 代码

```python
class Solution(object):
    def minTaps(self, n, ranges):
        """
        :type n: int
        :type ranges: List[int]
        :rtype: int
        """
        limits = [-1 for i in range(n + 1)]
        for i,rang in enumerate(ranges):
            if rang > 0:
                left = max(0, i - rang)
                right = min(n, i + rang)
                limits[left] = max(limits[left], right)
        # greedy way
        res = 0
        max_now = -1
        max_next = limits[0]
        for i in range(n + 1):
            # max_next = max(max_next, limits[i]) 只能削足适履写到下面去
            if max_now < i:
                if max_next < i:
                    return -1
                max_now = max_next
                res += 1
            max_next = max(max_next, limits[i])
        return res
```