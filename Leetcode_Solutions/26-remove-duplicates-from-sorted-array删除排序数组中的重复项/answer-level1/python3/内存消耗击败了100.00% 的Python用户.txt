#### 思路：
一个指针,与前一个比较，一样就pop掉，不一样就指针继续向后移动一位
#### 代码
```
class Solution(object):
    def removeDuplicates(self, nums):
        index = 1
        while index < len(nums):
            if nums[index - 1] == nums[index]:
                nums.pop(index)
            else:
                index = index+1
        return len(nums)
```
