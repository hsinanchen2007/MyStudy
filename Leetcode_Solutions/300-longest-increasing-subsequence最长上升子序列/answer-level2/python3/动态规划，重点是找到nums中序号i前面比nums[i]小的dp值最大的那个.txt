### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums) -> int:
        if not nums:
            return 0
        dp = [1 for _ in range(len(nums))]
        max_tmp = 1
        for i in range(1,len(nums)):
            ##记录dp最大的值
            tmp = float("-inf")
            for key in range(i):
                ##找到i前面比nums[i]小的dp值最大的那个
                if nums[i] > nums[key] and dp[key] > tmp:
                    tmp = dp[key]
            if tmp != float("-inf"):
                dp[i] = tmp+1
            if dp[i]>max_tmp:
                max_tmp = dp[i]

        return max_tmp
            



                

                
```