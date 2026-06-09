### 解题思路
![image.png](https://pic.leetcode-cn.com/dd221f0c2fa73c55869b3f96973681f8bdf745c6f563eaedc883d73085e733dd-image.png)


### 代码

```python3
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        assert len(nums) > 1
        res = [1] * len(nums)
        C = 1
        for i in range(1, len(nums)):
            C *= nums[i - 1]
            res[i] *= C
        C = 1
        for i in range(len(nums) - 2, -1, -1):
            C *= nums[i + 1]
            res[i] *= C
        return res

        
```