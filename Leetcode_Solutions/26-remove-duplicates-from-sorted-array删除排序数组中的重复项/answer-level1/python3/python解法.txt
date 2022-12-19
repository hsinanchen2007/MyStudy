### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        size = len(nums)
        curr = 1
        cnt = 1
        left = nums[0]
        while curr < size:
            right = nums[curr]
            if left != right:
                nums[cnt] = right
                cnt += 1
            left = right
            curr += 1
        return cnt
    ```