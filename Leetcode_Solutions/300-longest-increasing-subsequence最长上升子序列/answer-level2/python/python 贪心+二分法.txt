### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        cur_nums = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > cur_nums[-1]:
                cur_nums.append(nums[i])
            else:
                l, r = 0, len(cur_nums) - 1
                while l <= r:
                    mid = (l + r) / 2
                    if cur_nums[mid] < nums[i]:
                        l = mid + 1
                    elif cur_nums[mid] > nums[i]:
                        r = mid - 1
                    else:
                        l = mid
                        break
                cur_nums[l] = nums[i]
        return len(cur_nums)
```