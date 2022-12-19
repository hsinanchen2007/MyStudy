### 解题思路
在零元素的位置插入元素零，并弹出最后一个元素。

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        while i < len(arr):
            if not arr[i]:
                arr.insert(i, 0)
                arr.pop()
                i += 2
            else:
                i += 1
                
```