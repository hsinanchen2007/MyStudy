```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        size = len(nums)
        if size == 0 or k == 0:
            return []

        res = []
        index = 0
        pos = 0

        while pos <= size - k:
            '''当上一个滑动窗口内的最大值，不在当前窗口内时，只能重新找最大值'''
            if pos == 0 or pos > index:
                index = pos
                for i in range(pos, pos + k):
                    if nums[i] > nums[index]:
                        index = i 
            '''
            当上一个滑动窗口内的最大值在当前窗口内时
            只需要对比最新进入框内的[pos + k - 1]和上一个最大值
            '''
            elif index >= pos:
                if nums[pos + k - 1] > nums[index]:
                    index = pos + k - 1
            res.append(nums[index])
            pos += 1
        return res



```
