### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        arr += [-1]
        i = 2
        while i<len(arr):
            arr[-i] = max(arr[-i],arr[1-i])
            i += 1
        arr = arr[1:]
        return arr
```