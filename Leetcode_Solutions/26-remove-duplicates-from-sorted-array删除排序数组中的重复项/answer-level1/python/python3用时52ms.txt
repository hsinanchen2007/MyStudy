### 解题思路
降低执行用时的关键是运用“有序数组”这一点。运用快慢指针，快指针用于遍历数组，慢指针更新数组。首先将慢指针length置0，当快指针的数值等于慢指针的数值，继续遍历，否则慢指针+1，将快指针数值付给慢指针指向的位置。
这道题如果不要求，O(n) 的时间复杂度， O(1) 的空间复杂度的话，会很简单。 但是这道题是要求的，这种题的思路一般都是采用双指针

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = 0
        for i in range(1,len(nums)):
            if nums[i] == nums[length]:
                continue
            else:
                length += 1
                nums[length] = nums[i]
        return length+1

```