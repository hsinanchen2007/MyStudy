### 解题思路
        m = max(sum([nums.count(j[0]), nums.count(j[1])) for j in pair])，用sum函数就运行报错，好奇怪。


### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        l = list(set(nums))
        ll = []
        l.sort()
        pair = []
        i = 1
        while i < len(l):
            if l[i] - l[i-1] == 1:
                pair.append([l[i-1], l[i]])
            i += 1
        if len(pair)<1:
            return 0
        m = max([nums.count(j[0]) + nums.count(j[1]) for j in pair])
        return m
```