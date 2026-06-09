### 解题思路
排序？

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr:
            return None
        arr.sort()
        res = []
        for i in range(k):
            res.append(arr[i])
        return res
```