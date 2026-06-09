### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        res = []
        d = {}
        for i in arr:
            t = str(bin(i))
            n = t.count('1')
            if n not in d:
                d[n] =[]
            d[n].append(i)

        for i in sorted(d):
            res+=sorted(d[i])
        return res
```