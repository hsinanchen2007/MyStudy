### 解题思路
1-> 10 ** 1 - 1
2-> 10 ** 2 - 1
3-> 100 ** 3 - 1

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [ x for x in range(1, 10 ** n)]
```