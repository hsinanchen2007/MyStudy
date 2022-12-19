### 解题思路
此处撰写解题思路
思路很重要
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        lennums=len(nums)
        sum=nums[0]
        maxsum=sum
        for i in range(1,lennums):
            #有效累加
            if sum+nums[i] > nums[i]:
                maxsum = max(maxsum,sum+nums[i]) #max 取最大值
                sum=sum+nums[i]
            else: #累加和sum 加上i的值，比i的值还小，表示累加和sum无效，此时sum 应该为i的值
                maxsum = max(maxsum,sum,sum+nums[i],nums[i])  #max 取最大值
                sum=nums[i]
        return maxsum

```