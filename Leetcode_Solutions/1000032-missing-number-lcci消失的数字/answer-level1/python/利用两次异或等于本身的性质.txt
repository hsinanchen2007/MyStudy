### 解题思路
此处撰写解题思路
对res从0-nums.length进行异或。
i 是顺序列表
nums[i] 是输入列表
### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
       res = 0
       for i in range(len(nums)):
           res ^= i
           res ^=nums[i]
       res ^= len(nums)
       return res
```