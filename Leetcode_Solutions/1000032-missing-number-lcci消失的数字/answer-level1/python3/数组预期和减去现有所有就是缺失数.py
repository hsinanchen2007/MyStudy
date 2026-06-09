### 解题思路
此处撰写解题思路
数组预期和减去现有所有就是缺失数
### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nsum = len(nums)*(len(nums)+1)/2
        for i in nums:
            nsum=nsum-i
        return int(nsum)
```