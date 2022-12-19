### 解题思路
自己看吧 65ms左右

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.   #注意，人家这里写了  用nums
        """
                
        n = len(nums)
        if (k < n) & (k > 0):
            nums[:] = nums[-k:]+nums[:(-k)]
        elif  k > n:
            l = k % n
            nums[:]  = nums[-l:]+nums[:(-l)]
        else:
            nums[:]  = nums
        # return temp
```