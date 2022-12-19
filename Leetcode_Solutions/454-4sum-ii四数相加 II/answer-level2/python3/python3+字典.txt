### 解题思路
这个题的思路好像前面有好多道题都用过

### 代码

```python3
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        d = collections.Counter(a + b for a in A for b in B)
        res = 0
        for a in C:
            for b in D:
                if -(a + b) in d:
                    res += d[-(a + b)]
        return res
```