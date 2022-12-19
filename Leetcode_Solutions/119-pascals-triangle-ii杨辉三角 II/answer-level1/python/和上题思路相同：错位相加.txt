### 解题思路
和上题思路相同：错位相加

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        while len(res) <= rowIndex:
            res = [a+b for a, b in zip([0] + res, res + [0])]
        
        return res
```