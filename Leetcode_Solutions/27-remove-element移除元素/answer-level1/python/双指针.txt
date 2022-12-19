### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # 双指针
        left = 0
        n = len(nums)
        while left < n:
            if nums[left] == val:
                nums[left] = nums[n - 1]
                n -= 1
            else:
                left += 1
        return n

```