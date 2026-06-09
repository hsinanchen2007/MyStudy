

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l=len(nums)
        while k>=l:
            k-=l
        temp = nums[l-k:l]
        nums[k:l]=nums[0:l-k]
        nums[0:k]=temp
```
![image.png](https://pic.leetcode-cn.com/25d89b86e18d19a73473392613b463bdfed8e76a22deff4a4dc1f4c9e82fbc60-image.png)
