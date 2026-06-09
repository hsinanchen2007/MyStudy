### 解题思路
先举几个例子，归纳下规律，然后 `O(n)`遍历即可；
注意等号发生时候的情况；

### 代码

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # first find a non-ascending from tail
        ed = len(nums) - 2
        while ed > -1 and nums[ed] >= nums[ed+1]:
            ed -= 1
        if ed == -1:
            nums.reverse()
            return
        st = ed
        ed = len(nums) - 1
        # find first element larger than nums[st]
        while ed > st and nums[ed] <= nums[st]:
            ed -= 1
        nums[st], nums[ed] = nums[ed], nums[st]
        part = nums[st+1:]
        nums[st+1:] = part[::-1]
```