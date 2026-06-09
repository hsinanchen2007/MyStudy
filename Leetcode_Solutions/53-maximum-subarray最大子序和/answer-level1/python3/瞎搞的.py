### 解题思路
简单的说就是【1，2，3，-1，2，-5，1，2，-5，7】
分为【1，2，3，-1】 max = 6 sum =5
【4，-5】 max = 4 sum =-1    #5+4 = 9
【1，2，-5】 max = 3 sum = -2  #5-1+3 = 7
【7】 max = 5 sum = 5   #5 -1 -2 +5 = 7
判断和最大值的关系
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        res = max(nums)
        if res < 0:
            return res
        lam = 0
        for i in nums:
            if i >= 0 and lam < 0:
                lam = 0
            lam += i
            res = max(res,lam)
        return res
```