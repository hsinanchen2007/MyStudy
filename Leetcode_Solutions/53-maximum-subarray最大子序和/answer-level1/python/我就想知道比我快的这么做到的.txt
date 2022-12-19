### 解题思路
最大串一定是正数开始，其他不用管

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        midle = 0
        maxsum = 0
        for i in nums:
            midle = midle +i
            if(midle> 0):
                if(midle > maxsum):
                    maxsum = midle
            else:
                midle = 0
        if maxsum<=0:
            maxsum = max(nums)
        return maxsum


```