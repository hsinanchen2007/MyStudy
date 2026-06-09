### 解题思路

摩尔投票法牛b，快去看看吧！


### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        cc = 0
        for i in range(n):
            if cc == 0:
                res = nums[i]
                cc = 1
            else:
                if nums[i] ==res:
                    cc += 1
                else:
                    cc -= 1
        if cc >0:
            return res 

```
