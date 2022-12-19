# 方法一
```
class Solution:
    def removeDuplicates(self, nums):
        i=0
        while i < len(nums):
            temp = nums[i]
            try:
                while temp == nums[i+1]:
                    del nums[i+1]
            except:
                pass
            i+=1
        return len(nums)
```
感觉用try模块有点取巧吧，主要是判断i和i+1是否相同
# 不适用try模块
```
class Solution:
    def removeDuplicates(self, nums):
        i=0
        while i < len(nums)-1:
            temp = nums[i]
            while temp == nums[i+1]:
                del nums[i+1]
                if i == len(nums)-1:
                    break
            i+=1
        return len(nums)
```
# 方法二
```
class Solution:
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        p = 0
        q = 0
        while q < len(nums)-1:
            if nums[q] < nums[q+1]:
                p+=1
                q+=1
                nums[p]=nums[q]
            else:
                q += 1
        return p+1

```

双指针，48ms，用快指针来判断是否读到一个新值