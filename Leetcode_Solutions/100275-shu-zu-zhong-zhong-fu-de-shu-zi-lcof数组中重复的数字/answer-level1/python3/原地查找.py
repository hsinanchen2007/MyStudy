### 解题思路
执行用时 :48 ms, 在所有 Python3 提交中击败了90.92% 的用户
内存消耗 :22.7 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # dic = {}
        # for k in nums:
        #     if dic.get(k, False) != False:
        #         return k
        #     else:
        #         dic[k] = 1
        # return -1
        for index, val in enumerate(nums):
            if index != val and nums[val] == val:
                return val
            else:
                nums[index], nums[val] = nums[val], nums[index]
```