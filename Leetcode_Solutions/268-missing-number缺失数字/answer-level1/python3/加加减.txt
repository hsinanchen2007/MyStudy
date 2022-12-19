### 解题思路
题意是找寻未出现的数，我们只要计算0~n的总和再减去数组内数的总和即可

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return sum(range(0,len(nums)+1))-sum(nums)
```