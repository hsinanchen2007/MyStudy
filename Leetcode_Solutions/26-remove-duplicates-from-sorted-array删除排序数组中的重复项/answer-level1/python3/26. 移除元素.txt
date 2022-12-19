### 解题思路
1. 逆遍历

正向遍历会存在数组索引越界问题，逆遍历避免了删除元素后的索引越界问题

时间复杂度O(n^2)

空间复杂度O(1)

但是每次删除数组元素时会进行大量的数据迁移

2. 双指针法

初始状态，一个前指针，一个后指针

前指针和后指针指向的数字相等，前指针向前一步

前指针和后指针指向的数字不同，后指针向前一步，把前指针指向的值赋给后指针指向的位置

时间复杂度O(n)

### 代码

```python3
class Solution:
    '''
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return len(nums)
        length = len(nums)
        for index in range(length-1,0,-1):
            if nums[index] == nums[index-1]:
                nums.remove(nums[index])
        return len(nums)
    '''
    
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return len(nums)
        i = 0
        for j in range(1,len(nums)):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
        return i+1
```