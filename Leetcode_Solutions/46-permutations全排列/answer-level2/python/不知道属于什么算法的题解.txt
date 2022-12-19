from copy import deepcopy
import math
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        elif len(nums) == 1:
            return [nums]
        else:
            length = len(nums)
            res = [[nums[0]]]
            temp_length = 1
            while temp_length < length:
                to_add = nums[temp_length]
                add_index = 0
                new_res = []
                while add_index <= temp_length:
                    for r in res:
                        x = deepcopy(r)
                        x.insert(add_index, to_add)
                        new_res.append(x)
                    add_index += 1
                res = new_res
                temp_length += 1
            return res