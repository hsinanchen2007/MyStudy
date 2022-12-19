已知目前总共有n家，小偷从前1，2，3......n家可获得的最大收益用一个gains数组表示，那么我们需要求得的结果就是gains[n-1]
对于第i个房屋来说无非两种情况：被偷或者不被偷，用1表示被偷，0表示不被偷，那么
![IMG_20190911_231226.jpg](https://pic.leetcode-cn.com/26e5cf4a6ba81319a6206f83319d8e8f03143c59d3f781268637fb7e2a9bc4a6-IMG_20190911_231226.jpg)
如上图，那么gains[i] = max(gains[i-1], gains[i-2]+ nums[i])
剩下的吧= 
###### 斜体
class Solution:
    def rob(self, nums: List[int]) -> int:
        def gain(nums):
            length = len(nums)
            if length == 0:
                return 0
            elif length == 1:
                return nums[0]
            elif length == 2:
                return max(nums[0], nums[1])
            gains = [0*i for i in range(length)]
            gains[0] = nums[0]
            gains[1] = max(nums[0], nums[1])
            for i in range(2, length):
                gains[i] = max(gains[i-2] + nums[i], gains[i-1])

            return gains[-1]
        return gain(nums)