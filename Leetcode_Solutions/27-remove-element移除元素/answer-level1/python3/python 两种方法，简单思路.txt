时间O(n^2)，不需要额外空间。 简单思路，查到就删除，返回数组即可。因为删除，效率低

```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
        return len(nums)
```

时间O(N)，空间o(1)，双指针，j指针用来遍历数组，查到不等于val的，覆盖掉i位置的，初始为0位置，i加一，等待下一个不等的覆盖用。即从前往后覆盖。
最终，待覆盖位置前放的都是不等于val的，也就等于它们的数量。
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i=0
        for j in nums:
            if j!=val:
                nums[i]=j
                i+=1
        return i
```
