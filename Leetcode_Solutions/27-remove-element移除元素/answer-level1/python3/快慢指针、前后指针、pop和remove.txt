一、快慢指针法
思路：慢指针总是在被赋值非val值后才加1，快指针从头至尾遇到val就跳过，遇到非val就赋值给慢指针。
                                            
```
class Solution:  # 快慢指针法(耗时60ms)
    def removeElement(self, nums: List[int], val: int) -> int:
        slow_index = 0
        fast_index = 0
        for fast_index in range(len(nums)):
            if nums[fast_index] == val:
                continue
            else:
                nums[slow_index] = nums[fast_index]
                slow_index += 1
        return slow_index]()
```


二、python的remove和pop可以利用一下
注意：for循环里当然不能用remove和pop，因为一旦remove之后，索引就改变了

```
 class Solution:  # pop() or remove()
     def removeElement(self, nums: List[int], val: int) -> int:
         if not nums: return 0
         i = 0
         while i < len(nums):
             if nums[i] == val:
                 nums.remove(nums[i])
                 # nums.pop(i)
             else:
                 i += 1
         return i
```


三、前后指针

```
 class Solution:  # 前后指针法(耗时40ms)
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        n = len(nums)
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n-1]  # 就算赋给的i是val值也没事，因为i没变所以下次循环还是会判断它
                n -= 1
            else:
                i += 1
        return n;
```
