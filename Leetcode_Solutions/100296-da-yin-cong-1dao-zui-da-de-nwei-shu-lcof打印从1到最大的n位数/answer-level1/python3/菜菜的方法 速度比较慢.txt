### 解题思路
根据n做出一个相匹配的最大数，然后for循环

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        max = int("9"*n)
        num = []
        for i in range (1, max+1):
            num.append(i)
        return num
```