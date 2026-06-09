### 解题思路
遍历数组添加元素，最后去掉多余的元素即可

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        n = len(arr)
        while i < n:
            if arr[i] != 0:
                i += 1
            else:
                arr.insert(i,0)
                i += 2
        num = len(arr) - n
        while num:
            arr.pop()
            num -= 1

```