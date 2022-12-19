### 解题思路
用PYTHON排序应该算作弊吧
### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        if k == 0:
            return []
        else:
            return arr[0:k]
```