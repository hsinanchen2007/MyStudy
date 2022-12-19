### 解题思路
建立双指针，一个指向第一个新数字，一个指向用于遍历的当前位置数字
同时，考虑到删除时数组长度变化，因此从尾部向头部遍历，用指向0判断遍历完成

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ll = len(nums)
        if ll <= 1:
            return ll
        j = ll - 2
        i = ll - 1
        cmpp = nums[i]
        while j > -1:
            if nums[j] == cmpp:
                nums.pop(j)
                j -= 1
            else:
                i = j
                j -= 1
                cmpp = nums[i]
        return len(nums)

```