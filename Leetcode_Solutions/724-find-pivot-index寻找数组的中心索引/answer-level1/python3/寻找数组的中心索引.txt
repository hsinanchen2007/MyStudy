### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        # for i in range(len(nums)):
        #     sumLeft = sum(nums[:i])
        #     sumRight = sum(nums[i+1:])
        
        #     if sumLeft == sumRight:
        #         return i
        #     else:
        #         continue
    
        # return -1

        # total = sum(nums)
        # part_sum = 0
        # for i, j in enumerate(nums):
        #     if part_sum == (total - j) / 2:
        #         return i
        #     part_sum += j
        # return -1

        # S = sum(nums)
        # leftsum = 0
        # for i, x in enumerate(nums):
        #     if leftsum == (S - leftsum - x):
        #         return i
        #     leftsum += x
        # return -1

        l, r, diff = 0, 0, [0] * len(nums)
        for i, j in zip(range(len(nums)), range(len(nums) - 1, -1, -1)):
            diff[i] += l; l += nums[i]; diff[j] -= r; r += nums[j]
        return diff.index(0) if 0 in diff else -1





```