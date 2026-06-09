![image.png](https://pic.leetcode-cn.com/799b5997a5fd50ab74f67005c63d928de56e40a0edbe99f2621b527a8a1a10df-image.png)


```
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()
        return max([0]+[nums[i]-nums[i-1] for i in range(1,len(nums))])
```
