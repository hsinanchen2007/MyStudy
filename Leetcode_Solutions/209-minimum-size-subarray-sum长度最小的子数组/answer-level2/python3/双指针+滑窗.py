    class Solution:
        def minSubArrayLen(self, s, nums):
            if sum(nums) < s:
                return 0
            if sum(nums) == s:
                return len(nums)
            left = 0
            right = 0
            sub_sum = 0
            length = len(nums)
            for right, item in enumerate(nums):
                sub_sum += item
                while sub_sum >= s:
                    length = min(length, right - left + 1)
                    sub_sum -= nums[left]
                    left += 1
            return length

滑动窗口, 左右指针确定滑动窗口大小

![Screenshot from 2019-07-06 15-11-03.png](https://pic.leetcode-cn.com/2d26dec758c8fe1af04decea7f2a539631b9705b0d2272cab0a6e7ff62676a45-Screenshot%20from%202019-07-06%2015-11-03.png)
