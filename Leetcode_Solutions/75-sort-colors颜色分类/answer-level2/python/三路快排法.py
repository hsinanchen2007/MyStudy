### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        思路：三路快排, 设置三个指针游标
        """
        zero = -1
        two = len(nums) # 表示为2的数的初始指针
        i = 0
        while i < two:
            if nums[i] == 1:
                i += 1
            elif nums[i] == 2: # 将2换到数组的最后去
                two -= 1 # 指针向数组头前移一位
                tmp = nums[i]
                nums[i] = nums[two]
                nums[two] = tmp
            else:
                zero += 1 # 指针向数组尾移一位
                tmp = nums[i]
                nums[i] = nums[zero]
                nums[zero] = tmp
                i += 1
                
            
                
```