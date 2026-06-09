### 解题思路
直接用range生成1到10的N次方的列表。

### 代码

```python3
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [*range(1,10 **n)]
```