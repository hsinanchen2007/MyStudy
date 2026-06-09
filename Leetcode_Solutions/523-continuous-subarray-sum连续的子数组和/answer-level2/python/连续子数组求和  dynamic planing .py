### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if len(nums)<=1:
            return False
        dp = [0]*len(nums)
        dp[0] = nums[0]

        for i in range(1,len(nums)):
            dp[i] = dp[i-1]+nums[i]
        
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                sums = dp[j]-dp[i]+nums[i]
                if k==0:
                    if sums==0:
                        return True
                else:
                    if sums%k==0:
                        return True

        return False


```


区间差检验方式
python solution