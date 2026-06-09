```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 0.1 当输入为 [] 的处理:
        if len(nums) == 0:
            return 0
        # 0.2 当输入为 [x] 的处理:
        if len(nums)== 1:
            return nums[0]

        count = 0
        # 1.1 当不选择第0号房屋时: 
        # [0, x1, ..., xN]
        nums0 = nums[0]
        nums[0] = 0

        stole0 = 0
        stole1 = nums[0]
        for i in range(1, len(nums)):
            steal0 = max(stole0, stole1)
            steal1 = nums[i] + stole0
            stole0 = steal0
            stole1 = steal1
        count0 = max(steal0, steal1)

        # 1.2 当不选择最后的房屋时: 
        # [x0, x1, ..., 0]
        nums[0] = nums0
        nums[-1] = 0

        stole0 = 0
        stole1 = nums[0]
        for i in range(1, len(nums)):
            steal0 = max(stole0, stole1)
            steal1 = nums[i] + stole0
            stole0 = steal0
            stole1 = steal1
        count1 = max(steal0, steal1)

        return max(count0, count1)
```

![image.png](https://pic.leetcode-cn.com/ba6345b66e7b8a4109829599b0208854602a45163b6d488e8ac1af71d343f6e8-image.png)
