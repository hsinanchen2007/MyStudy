### 解题思路
c = (3(a+b+c)-(a+a+a+b+b+b+c))/2

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3*sum(list(set(nums)))-sum(nums))//2
```