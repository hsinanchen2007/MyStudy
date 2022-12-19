### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        length = len(arr)
        arr_max = max(arr)
        for i in range(length-1):
            if arr[i] == arr_max:
                arr_max = max(arr[i+1: length])
            arr[i] = arr_max
        arr[length-1] = -1
        return arr

```