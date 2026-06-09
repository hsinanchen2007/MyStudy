python 双端队列
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        window,result = [],[]          #window里存nums的下标
        for i,value in enumerate(nums):
            if i >= k and i - window[0] >= k:
                window.pop(0)         #左端出对
            while window and nums[window[-1]] <= value:
                window.pop()          #右端出队
            window.append(i)  
            if i >= k-1:
                result.append(nums[window[0]])
        return result

