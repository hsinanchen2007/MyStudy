```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(nums) == 0:
            return nums
        c0 = len(nums[0])
        r0 = len(nums)
        if r*c != r0*c0:
            return nums
        result = [[0]*c for _ in range(r)]
        for i in range(r):
            for j in range(c):
                t = i*c+j
                result[i][j] = nums[t//c0][t%c0]
        return result
```
