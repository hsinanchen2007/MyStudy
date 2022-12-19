### 解题思路

每一层递归到上一层，注意当 numRows == 0 的情况

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        upper = self.generate(numRows - 1)
        upper.append([1] + [upper[-1][i-1] + upper[-1][i] for i in range(1, numRows-1)] + [1])
        return upper
```