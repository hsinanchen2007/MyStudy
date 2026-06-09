### 二分查找

```python []
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        i, j = 0, len(arr) - 1
        while i < j:
            k = (i + j) // 2
            if arr[k] > arr[j]:
                i = k + 1
            elif arr[k] < arr[j]:
                j = k
            else:
                j -= 1
        j = bisect.bisect_left(arr[: i], target)
        if j < len(arr) and arr[j] == target:
            return j
        j = bisect.bisect_left(arr[i: ], target)
        if i + j < len(arr) and arr[i + j] == target:
            return i + j
        return -1
```

### 列表解析

```python []
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        return next((i for i, a in enumerate(arr) if a == target), -1)
```
