### 解题思路
d = (3(a+b+c+d)-(a+a+a+b+b+b+c+c+c+d)) // 2

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3*sum(set(nums))-sum(nums))//2 
```