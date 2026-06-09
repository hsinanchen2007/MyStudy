### 解题思路
把数组排好序，然后和原数组对比就ok了
### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        up_sort=sorted(A)
        down_sort=sorted(A,reverse=True)
        if A==up_sort or A==down_sort:
            return True
        return False
```