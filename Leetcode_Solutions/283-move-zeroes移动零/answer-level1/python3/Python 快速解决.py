### 解题思路
用一个指针p表示为0的位置，另一个指针i来扫描数组。
当i遇到非零位置并且p的位置为0时，进行两个值的互换，此时p向前一步
当i遇到为0的位置并且p的位置不为0时，p要变成i

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        zero = 0
        for i in range(0, len(nums)):
            if nums[i] != 0 and nums[zero] == 0:
                nums[zero] = nums[i]
                nums[i] = 0
                zero += 1
            elif nums[i] == 0 and nums[zero] != 0:
                zero = i
```