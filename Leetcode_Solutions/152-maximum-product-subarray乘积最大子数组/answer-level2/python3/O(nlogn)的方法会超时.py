### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # result_num = max(nums)
        # n = len(nums)
        # if n == 1: return nums[0]
        # res = [[0 if i != j else nums[i] for i in range(n)] for j in range(n)]
        # for i in range(n-1):
        #     for j in range(i+1, n):
        #         res[i][j] = res[i][j-1] * res[j][j]
        #         if res[i][j] > result_num:
        #             result_num = res[i][j]
        
        # return result_num
        max_res = float("-inf")
        imax = 1
        imin = 1

        for i in range(len(nums)):
            if nums[i] < 0:
                imax, imin = imin, imax
            imax = max(imax*nums[i], nums[i])
            imin = min(imin*nums[i], nums[i])
            max_res = max(max_res, imax)
           # print(max_res)
        return max_res
```