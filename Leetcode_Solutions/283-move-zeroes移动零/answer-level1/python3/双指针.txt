### 解题思路
设置两个指针。i ， j
i 随着对列表进行遍历移动
当遇到非零值时，指针i所指的值和指针j所指的值进行交换。
并且将指针j向前移动。
当没有遇到零值时，指针i和j同步移动。
当遇到了零时，指针i,j都指向零值。但是接下来指针i继续向前移动，指针j还停留在零值处。
直到指针i遇到下一个非零值，此时j一直停留在第一个零值处。将i处的非零值与j处的零值互换。
互换后，j向前移动，指向移动后零值的位置或下一个零值。
在循环过程中，j一直指向的都是列表当前的第一个零值。所以在遍历列表时，只要i遇到了非零值都会和列表的第一个非零值互换。直到不再有非零值出现。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        return nums
```