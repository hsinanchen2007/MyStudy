### 解题思路
安排两个计数器，遇到I，加小的；遇到D，加大的

### 代码

```python3
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        small = 0
        big = len(S)
        res = []
        for i in S:
            if i == 'I':
                res.append(small)
                small += 1
            else:
                res.append(big)
                big -= 1
        if S[-1] == 'I':
            res.append(res[-1] + 1)
        else:
            res.append(res[-1] - 1)
        return res
```