### 解题思路
也是用两个指针，一前一后，从数组后面往前面遍历，
如果等于设定值，就把它留在后面，右指针左移一位。
如果不等于设定值，就把它放到前面，跟左指针换一下位置，左指针往右一位，
两个指针相遇的时候，判断一下相遇的值，是否是设定值。

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        if not nums:
            return 0
        l = 0
        r = len(nums) - 1
        while l != r:
            if nums[r] == val:
                r -= 1
            else:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1

        return l + 1 if nums[l] != val else l





```