
```python []
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        length=len(nums)
        for i in range(length):
            index =nums[i]
            if index> length:
                index-=length
            if nums[index]>=length:
                return index
            nums[index]+=length
        return -1
```
只需要遍历一遍数组，遍历到当前下标i的时候，判断当前下表i的值是否大于len(nums),
如果大于的话先减去len(nums)变回原来的数字，然后nums[nums[i]]是否大于len(num)，如果大于的话说明已经被访问过一次了，所以直接返回。