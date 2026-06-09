### 解题思路
punch in the card. 
Again I will give you code. 

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums):
        if len(nums)==0:
            return 0
        log=[0 for i in range(len(nums))]
        for i in range(len(nums)):
            m=0
            for j in range(i):
                if nums[j]<nums[i]:
                    m=max(m,log[j])
            log[i]=m+1
        return max(log)
```