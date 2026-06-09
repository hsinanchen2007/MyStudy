### 解题思路
py很方便，就一行代码return sorted(arr)[:k]

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return sorted(arr)[:k]
```