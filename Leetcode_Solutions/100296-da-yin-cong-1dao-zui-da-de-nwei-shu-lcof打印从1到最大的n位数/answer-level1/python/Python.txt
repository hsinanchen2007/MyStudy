### 解题思路
`range()`一行代码搞定

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return list(range(1, 10 ** n))
```