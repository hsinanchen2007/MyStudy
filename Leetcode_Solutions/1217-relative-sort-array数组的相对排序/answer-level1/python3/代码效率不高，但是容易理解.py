### 解题思路


### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        L = []
        for num in arr2:
            count = arr1.count(num)
            L += [num] * count
        L += sorted([i for i in arr1 if i not in arr2])
        return L
```