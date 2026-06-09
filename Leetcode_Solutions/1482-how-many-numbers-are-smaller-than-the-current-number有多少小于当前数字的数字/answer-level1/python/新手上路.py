### 解题思路
#比较每一个与其他的大小，
### 代码

```python
class Solution(object):
    def smallerNumbersThanCurrent(self,nums):
        """检测小的数字"""
        a = len(nums)
        c = 0
        d = 0
        e = []
        while c < a:
            for b in nums:
                if nums[c] > b:
                    d = d + 1
            e.append(int(d))
            d = 0
            c = c + 1 
        return e




```