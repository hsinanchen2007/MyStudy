### 解题思路
对于0~n之间的数字，元素和索引，只有一个数字出现了一次，其余都是两次
又因为异或有这样一个特点:
ans = ans^x^x^y^y^u^u,其中，ans就是那个仅出现一次的数字，因此，进行异或即可将这个数字的出来

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        #异或算法
        r = 0
        for i in range(len(nums)):
            r ^= i^nums[i]
        r ^= len(nums)
        return r

        # n = [i for i in range(len(nums)+1)]
        # for c in n:
        #     if c not in nums:
        #         return c
```