### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s,n,mm =0,0,nums[0]
        for i in nums:
            s +=i
            n = max(s,i)
            mm = max(mm,n)
            s = n 
        return mm 

```