### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        return sum(1 for i in arr1 if all(abs(i - j) > d for j in arr2))
```