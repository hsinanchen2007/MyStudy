### 解题思路
运行整体移动元素法 
假设 nums = [1,2,3,4,5,6,7]
k = 3 
结果 => [5,6,7,1,2,3,4]
把[5,6,7] 整块搬运到k之前
把[1,2,3,4]整块搬运到k后面
### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            return 
        k = k % len(nums)                  #避免k大于nums长度
       
        temp = nums[len(nums) - k:]         #5,6,7
        nums[k:] = nums[:len(nums) - k]     #1,2,3,4 
        nums[:k] = temp 
        return  

```