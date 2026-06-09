贪心算法：总是记录当前能达到的最远位置，若存在一个位置i，前面所有节点能够达到的最远位置小于i，则无法继续走下去，返回False。
```
class Solution:
    def canJump(self, nums):
        """
        :param nums: List[int]
        :return: bool
        """

        x = 0  # 当前能达到的最远位置
        for i in range(len(nums)):
            if x < i:
                return False
            x = max(x, i+nums[i])
        return True
```
