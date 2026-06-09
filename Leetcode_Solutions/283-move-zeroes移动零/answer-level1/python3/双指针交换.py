### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = 0
        i = 0
        while i < len(nums) - cnt:
            if nums[i] == 0:
                cnt += 1
                k = i
                for j in range(i + 1, len(nums)):
                    nums[j], nums[i] = nums[i], nums[j]
                    i += 1
                i = k
                if nums[i] != 0:
                    i += 1
            else:
                i += 1
```