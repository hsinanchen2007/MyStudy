### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        result = 0
        for num_1 in arr1:
            for num_2 in arr2:
                if abs(num_1 - num_2) <= d:
                    break
            else:
                result += 1
        return result
```