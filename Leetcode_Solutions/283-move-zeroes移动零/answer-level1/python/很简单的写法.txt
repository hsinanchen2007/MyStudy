### 解题思路
很简单的写法，没使用双指针

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        temp, len_ = 0, len(nums)
        while temp < len_:
            if nums[temp] == 0:
                del nums[temp]
                len_ -= 1
                nums.append(0)
                continue
            temp += 1
```