### 解题思路
当存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d时，减1。

### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        ans = len(arr1)
        for i in arr1:
            for j in arr2:
                if abs(i - j) <= d:
                    ans -= 1
                    break
        return ans 

```