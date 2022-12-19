### 解题思路
刚开始不习惯，看着这个简单就试下，发现了自己与别人的差距

### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        res=0
        for i in arr1:
            for j in arr2:
                if abs(i - j) <= d:
                    break
            else:
                res += 1
        return res
```