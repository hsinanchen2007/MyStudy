### 解题思路
当target在nums里时，一个遍历循环就可以搞定；如果不在，那就先把target加人nums中，在来冒泡排序（只学过这个）nums，使其成为有序数组，再重复第一步。（这样做的缺点不言而喻：时间复杂度太高，提交时容易超时，要多提交几次）

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i]==target:
                return i
        nums.append(target)
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]>nums[j]:
                    nums[i],nums[j]=nums[j],nums[i]
        for i in range(len(nums)):
            if nums[i]==target:
                return i
```