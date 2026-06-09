遍历数组，数组中起码有一个数，则count初始化为1，当前项和下一项不同的时候，则使数组中count位置的数等于下一项，然后count自增1
```
代码块
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count=1
        for i in range(0,len(nums)-1):
            if nums[i]==nums[i+1]:
                continue
            else:
                nums[count]=nums[i+1]
                count+=1
        return count
```
