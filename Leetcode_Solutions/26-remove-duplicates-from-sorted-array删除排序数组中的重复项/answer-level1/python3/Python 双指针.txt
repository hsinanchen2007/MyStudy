使用两个指针p1,p2，p1初始位置为0，p2初始位置为1。
然后循环遍历nums。
如果p1和p2所指的值相同，删除p1所指位置的值，此时数组会自动向前填充，因此两个指针不用移动。
如果p1和p2所指的值不同，那么将p1,p2分别移向下一个位置。
直到p2到达数组的尾部，整个过程完成。
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p1 = 0
        p2 = 1
        while p2 <len(nums):
            if nums[p1] == nums[p2]:
                del nums[p1]
            else:
                p1+=1
                p2+=1
        return len(nums)
```
