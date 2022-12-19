新手很容易和我一样使用错误思路1或2
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # 错误的思路1：循环过程中nums在变化
        # for n in nums:
        #     if n == val:
        #         nums.remove(n)
        # return len(nums)
        
        # 错误的思路2：循环过程中nums长度变化，实际上还是nums在变化
        # for i in range(len(nums)):
        #     if nums[i] == val:
        #         nums.remove(val)
        # return len(nums)
        
        # 正确思路1: 2次for循环 时间复杂度O(n^2)，因为在for循环中使用了remove()操作 
        # i = 0
        # for n in nums:
        #     if n == val:
        #         i += 1
        # if i > 0:
        #     for _ in range(i):
        #         nums.remove(val)
        # return len(nums)  
    
        # 正确思路2：双指针发 时间复杂度为O(n)
        # slow = 0
        # for fast in range(len(nums)):
        #     if nums[fast] != val:
        #         nums[slow] = nums[fast]
        #         slow += 1
        # return slow
    
        # 正确思路3: 倒序for循环，解决错误思路2中的问题，虽然for循环过程中nums长度也在变，但倒序不会导致下标越界，时间复杂度为O(n)
        for i in range(len(nums)-1, -1, -1):
            if nums[i] == val:
                nums.remove(val)
        return len(nums)

```
正确思路1的时间复杂度应该是O(n^2), 如果我没分析错的话。倒序for循环是最简单又好理解的