单次遍历 每次比较25%之后的元素
```
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        t = len(arr) // 4 + 1
        for i in range(0, len(arr) - t + 1):
            if arr[i] == arr[i+t-1]:
                return arr[i]
        return 0
```
