### 解题思路
题目给定的数值数量是有限的只有0，1，2，要进行排序，可以运用三个指针，分别标识0的右边界i、2的左边界j以及当前遍历到的位置k，每遍历到0，将当前值与i位置值交换同时i+1，遍历到2，将当前值与j位置交换同时j-1，遍历到1不操作继续向后遍历
### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        j = len(nums) - 1
        k = 0
        while k <= j:
            if nums[k] == 0:
                if i == k:
                    k += 1  
                    i += 1
                    continue
                nums[k],nums[i] = nums[i],nums[k]             
                i += 1
            elif nums[k] == 1:
                k += 1
            elif nums[k] == 2:
                if j == k:
                    j -= 1
                    k += 1
                    continue
                nums[k],nums[j] = nums[j],nums[k]
                j -= 1
            
```