### 解题思路
最小值移除，添加到结果中

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if arr == '':
            return '[]'
        result = []
        for i in range (0, k):
            a = min(arr)
            arr.remove(a)
            result.append(a)
        return result
```