这题和第26题非常相像，都可以采用双指针求解。
在26题中，当快指针指向的值于慢指针相等时，快指针向前移动，用于跳过重复值，如果不相等，则慢指针向前移动，结果集加一。
然后让慢指针的值等于快指针的值，此时跳过了相等的值。

参考26解题思路，这一题可用同样的方法，只不过指针改变的临界条件发生改变。
在26题中是要删去所有重复的值，所以 `if nums[fast] != nums[slow]: slow +=1`
而在本题中，可保留两个重复的数，即`nums[slow] != nums[fast] or nums[slow] != nums[fast+1] ：slow+=1`
考虑到越界情况，我们添加条件`if fast==len(nums)-1: slow+1`
最后，slow为最后一个不重复数的索引。 

```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #快慢指针
        slow = 0
        fast = 1
        if not nums:
            return 
        while fast < len(nums):
            if nums[slow] != nums[fast] or fast==len(nums)-1 or nums[slow] != nums[fast+1]:
                slow+=1
            nums[slow] = nums[fast]
            fast+=1
        return slow+1
```
时间复杂度：O(N)
空间复杂度：O(1)