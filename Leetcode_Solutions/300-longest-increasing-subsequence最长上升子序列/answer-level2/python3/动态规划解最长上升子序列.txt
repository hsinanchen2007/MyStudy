```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        '''
        动态规划：最长上升子序列
        dp方程：Fk = max(Fi + 1 | Ak > Ai, i in range(k))
        解释：Fk表示以k项结尾的最长子上升序列是：保证第i项值（Ai）比第K项值（Ak）小的情况下，
        遍历range(k)的范围，找到最大的 Fi+1 的值。
        '''
        status = [1]
        lenth = 0
        if len(nums) == 1:
            return 1
        for k in range(1,len(nums)):
            # Fk最差的情况就是Fk=1
            status.append(1)
            for i in range(k):
                # 遍历前k-1个状态，在保证第i项值（Ai）比第K项值（Ak）小的情况下，找到
                # 最大的上升子序列，便是Fk的解。
                if nums[k] > nums[i] and status[i]+1 > status[k]:
                    status[k] = status[i] + 1
            if lenth < status[k]:
                lenth = status[k]
                
        return lenth
```
