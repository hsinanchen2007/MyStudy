### 解题思路
采用双指针。应用双指针有两个关键问题，一是两个指针的初始值，二是两个指针的移动规则。两个关键问题如何解决需要据具体问题而定。本题是要将排序数组中的非重复元素置于数组左侧，将重复元素置于数组右侧，所以首先需要遍历整个数组，因此两个指针初始位置一个为0（慢指针）,一个为1（快指针）。快指针的作用是找到新的元素，慢指针的作用是保证该指针及该指针左侧不含重复元素，因此当快指针找到新元素后，慢指针值增加1,对应元素值为慢指针找到的新值。快指针遍历结束后，慢指针 + 1便为新数组的长度。

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 0
        fast = 1
        n = len(nums)
        while fast < n:
            if nums[fast] != nums[fast - 1]:
                low += 1
                nums[low] = nums[fast]
                fast += 1
            else:
                fast += 1
        new_length = low + 1
        return new_length
```