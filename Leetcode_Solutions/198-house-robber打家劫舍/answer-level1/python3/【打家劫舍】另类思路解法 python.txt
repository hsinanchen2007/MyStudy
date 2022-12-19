虽然过了但是看了第一个官方答案瞬间自闭，我发现我的思路总是有点清奇
既然这么写了就分享下，不知道有没有跟我想法一样的
假设这小偷有个毛病，走到第n号房的时候，他看上了这家就决定一定要偷这家
于是，S(n)为小偷一定要偷第n户的时候所能窃取的最大金额
因为偷了第n户，前面的第n-1户就不能偷，前面刚刚偷的就只能选择第n-2户或者第n-3户，就有方程：
S(n) = max(S(n-3)+house[n],S(n-2)+house[n])
python代码↓
```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # S(n) = max(S(n-3)+house[n],S(n-2)+house[n])
        if not nums:
            return 0
        if len(nums)==1:
            return nums[0]
        if len(nums)==2:
            return max(nums)
        max_rob_3 = 0   # n户往前数3户
        max_rob_2 = nums[0]  # n户往前数2户
        max_rob_1 = nums[1]  # n前面那户
        for rob in nums[2:]:
            max_rob_0 = max(max_rob_3 + rob, max_rob_2 + rob)
            max_rob = max(max_rob_0, max_rob_1)
            max_rob_3 = max_rob_2
            max_rob_2 = max_rob_1
            max_rob_1 = max_rob_0
        return max_rob
```
其实只是比常规答案多绕了个弯，单纯分享一下