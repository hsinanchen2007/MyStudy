### 解题思路
curr保存当前的和，M保存历史最大和。
总共有四种情况：
i为正,curr为正，curr+=i;
i为正，curr为负，舍弃curr，curr=i
i为负,curr为正，curr+=i;
i为负,curr为负，舍弃curr，curr=i
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        M = nums[0]
        curr = M 
        for i in nums[1:]:
            if i >= 0:
                if curr < 0:
                    curr = i
                else:
                    curr += i 
            else:
                if curr+i > 0:
                    curr += i 
                else:
                    curr = i 
                    
            if curr > M:
                M = curr 
        return M 
```