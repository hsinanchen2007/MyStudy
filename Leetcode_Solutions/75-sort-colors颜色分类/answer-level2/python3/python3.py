好像不太对
![UC截图20191204144316.png](https://pic.leetcode-cn.com/9404f75eeddd6ce1114f685142f28581a1715f19ea601b23464222e62f906c90-UC%E6%88%AA%E5%9B%BE20191204144316.png)
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = []
        m = []
        r = []
        for i in range(len(nums)):
            if nums[i] == 0:
                l.append(nums[i])
            elif nums[i] == 2:
                r.append(nums[i])
            else:
                m.append(nums[i])
        nums[:] = l + m + r
```

