### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums: return nums 
        n = len(nums)
        k = k % n 
        # nums[:] = nums[k:]+nums[:k] # 利用本身的list的性质
        self.reverse(nums, 0, n-1) # 翻转整个数组
        self.reverse(nums, 0, k-1) # 翻转前k个
        self.reverse(nums, k, n-1) # 翻转后面n-k个
        
    def reverse(self, nums, i, j):
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i+=1
            j-=1

        
```