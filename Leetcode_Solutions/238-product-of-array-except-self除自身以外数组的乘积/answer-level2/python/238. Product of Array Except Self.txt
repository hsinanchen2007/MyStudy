找规律, 左边乘积 * 左边乘积
```
"""
[1,2,3,4]
_m = left_m * right_m

i = 1: 1 * (2*3*4)
i = 2: 1 * (3*4)
i = 3: (1*2) * 4
i = 4: (1*2*3) * 1

left_m =  [1, 2, 3, 6]
right_m = [24, 12, 4, 1]
"""

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        L_left, L_right = [1], [1]
        i, j = 0, len(nums) - 1
        while(j > 0):
            L_left.append(L_left[-1] * nums[i])
            L_right.insert(0, L_right[0] * nums[j])
            i, j = i + 1, j - 1
        i, L = 0, []

        while(i < len(L_left)):
            L.append(L_left[i] * L_right[i])
            i += 1
        return L

print Solution().productExceptSelf([1,2,3,4])
```
