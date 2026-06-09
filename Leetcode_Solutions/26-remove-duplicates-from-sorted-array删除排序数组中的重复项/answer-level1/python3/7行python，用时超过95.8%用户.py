### 解题思路
遍历数组nums，当遇到与前数不同的值时，将其加入到新的数组末尾，新的数组通过覆盖原数组产生
设置一个指针p1,指向新数组末尾。
### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p1=0
        for i in nums:
            if i!=nums[p1]:
                p1=p1+1
                nums[p1]=i
        del nums[p1+1:]
        return len(nums)
```