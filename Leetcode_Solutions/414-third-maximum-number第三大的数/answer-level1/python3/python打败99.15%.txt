![image.png](https://pic.leetcode-cn.com/b5e62bef3236f5a1a59ec70023705f6084376d0705ca0e674229322d0793e090-image.png)

```python []
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse = True)
        index = 1 #第三大的数索引
        length = 1 #数组长度索引
        while index < 3 and length < len(nums):
            if nums[length-1]>nums[length]:
                index += 1
            length += 1
        if index == 3:
            return nums[length-1]
        else:
            return nums[0]
```

