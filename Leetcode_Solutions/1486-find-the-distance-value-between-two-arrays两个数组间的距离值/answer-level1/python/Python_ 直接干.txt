### 解题思路
嗯，就是直接上。$O(n^2)$
### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        res = 0
        for num in arr1:
            if all([abs(num - num2) > d for num2 in arr2]):
                res +=1
        return res
```