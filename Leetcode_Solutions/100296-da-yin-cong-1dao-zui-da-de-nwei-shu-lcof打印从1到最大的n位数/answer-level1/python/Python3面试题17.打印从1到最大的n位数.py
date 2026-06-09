### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
       
        res = []

        if n < 1:
            res = [0]

        elif n == 1:
            for i in range(1, 10):
                res.append(i)

        else:
            for i in range(1, 10**n):
                res.append(i)
        return res
```