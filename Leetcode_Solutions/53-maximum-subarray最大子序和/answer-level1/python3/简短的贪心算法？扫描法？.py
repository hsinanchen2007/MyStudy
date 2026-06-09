### 解题思路
依葫芦画瓢

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:       
        max_sum=cur=nums[0]
        for i in range(1,len(nums)):
            cur=max(nums[i],cur+nums[i])
            max_sum=max(max_sum,cur)   
        return max_sum
```