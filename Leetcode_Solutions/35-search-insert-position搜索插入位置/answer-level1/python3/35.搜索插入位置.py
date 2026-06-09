### 解题思路

![image.png](https://pic.leetcode-cn.com/5d8fb7ea1c93a39972dee4f1806bc9b9d8ef9538e2d86a79e3f9da3cd5f2b75f-image.png)

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        if nums[-1]<target:
            return len(nums)
            
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
                break

```