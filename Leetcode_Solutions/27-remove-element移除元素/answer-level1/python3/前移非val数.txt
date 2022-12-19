### 解题思路
对于非val数，前移当年下标之前找到过的非val个数

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cnt_val = 0
        cnt_nonval = 0
        length = len(nums)
        for i in range(0, length):
            if nums[i]==val:
                cnt_val += 1
            else:
                nums[i-cnt_val] = nums[i]
        return length-cnt_val
```