记录一下官方双指针解法
相当于（实际上并没有）在原数组nums相同的内存位置开辟了一个新数组，新数组就是答案数组
慢指针i指向新数组的元素
快指针找到要添加到新数组（答案数组）的元素后，添加到新数组
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        j=0
        for j in range(len(nums)):#i指向答案数组最后一个元素
            if nums[i]!=nums[j]:#j找到一个和答案数组中不重复的新元素，添加到答案数组中
                nums[i+1]=nums[j]
                i+=1
        return i+1

```
