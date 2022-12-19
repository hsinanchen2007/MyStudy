## 思路:

其实就是**两数之和**的扩展版

没啥好说的，遍历前两个数组可以相加得到所有值的个数，然后再遍历后两个数组，即可

时间复杂度$O(n^2)$

## 代码:

```python
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        lookup = collections.defaultdict(int)
        res = 0
        for a in A:
            for b in B:
                lookup[a+b] += 1
        for c in C:
            for d in D:
                res += lookup[-(c + d)]
        return res
        
```

