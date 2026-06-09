
```
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # dis表明当前位置可能前进的最大距离，用于判断是否能够到达下一个位置，dis小于0则表示无法前进
        dis = 0
        for iter in nums:
            if dis < 0:
                return False
            # 用当前位置的信息更新dis
            dis = max(dis - 1, iter - 1)
        return True
```
