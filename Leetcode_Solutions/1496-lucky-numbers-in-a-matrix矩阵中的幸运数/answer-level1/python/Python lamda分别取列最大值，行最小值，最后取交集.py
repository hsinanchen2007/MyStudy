
### 代码

```python3
class Solution:

    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row_min = list(map(lambda x: min(x), matrix))
        col_max = list(map(lambda x: max(x), zip(*matrix)))

        return list(set(row_min).intersection(set(col_max)))
```