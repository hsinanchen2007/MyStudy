先求能解决问题，再想优化策略
1. 从第i个元素开始，看看在没在nums[i]在没在nums[:i]
2. 如果在，说明是相同元素，就地删除，重新从这个位置开始循环
3. 不过不在，说明是不同元素，i+1，前进一步

```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 1
        while i < len(nums):
            if nums[i] in nums[:i]:
                del(nums[i])
                continue
            else:
                i += 1
        return i
```
