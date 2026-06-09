这个题目要掌握三个点：1，时空复杂度的要求；2，是一个已经排序的数组；3，删除的意思并不真正意义上的删除，可以移到数组后面。因此可以用快慢指针的方法，一个指向当前指针，一个遍历找到第一个不等于当前指针所指的数值的元素，然后放到当前指针的后一位。代码如下：
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0 or len(nums)==1:
            return len(nums)
        p,q =0,1
        while q<len(nums):
            if nums[p] != nums[q]:
                nums[p+1] = nums[q]
                p += 1
                q += 1
            else:
                q+=1
        return p+1
```