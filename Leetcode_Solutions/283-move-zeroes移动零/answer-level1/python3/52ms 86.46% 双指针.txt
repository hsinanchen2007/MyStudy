### 解题思路
a指针之前为非0，a和b所夹为0，向右遍历时，若遇到非0元素，将该元素与a交换位置

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        a = b = 0
        for b in range(len(nums)):
            if nums[b] != 0:
                nums[a], nums[b] = nums[b], nums[a]
                a += 1

```