### 解题思路
排序后取数。

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[0: k]
```