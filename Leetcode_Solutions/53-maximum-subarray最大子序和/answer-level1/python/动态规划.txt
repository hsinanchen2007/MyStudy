maxsum 保存当前找到的最大和
maxins 保存从idx开始到当前元素之前的和

如果maxins<0，说明idx应该从当前元素开始

如果maxins>maxsum，则说明找到了更大的子序列和，则更新maxsum

执行用时 :56 ms, 在所有 Python 提交中击败了98.92%的用户
内存消耗 :12.3 MB, 在所有 Python 提交中击败了33.95%的用户


class Solution(object):
    def maxSubArray(self, nums):
        
        maxsum = nums[0]
        maxins = maxsum 
        idx = 0
        
        for i in range(1, len(nums)):
            if maxins<0:
                idx = i
                maxins = nums[i]
            else:
                maxins = maxins + nums[i]
            
            if maxins>maxsum:
                maxsum = maxins
            

        return maxsum