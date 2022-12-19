```
class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        raw = len(nums) 
        colum = len(nums[0])
        if raw*colum != r*c:
            return nums
        
        result = [[] for i in range(r)]
        raw = 0
        colum = 0
        for temp in nums:
            for i in temp:
                if colum < c:
                    result[raw].append(i)
                    colum += 1
                else:
                    raw += 1
                    colum = 0
                    if raw < r:
                        result[raw].append(i)
                    colum += 1
        return result
```
