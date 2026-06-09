### 解题思路
主要是引入一个指针j，指向替换后不为0的位置；


### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # j是替换后不为零的位置
        count = len(nums)
        i,j = 0,0
        for i in range(count):
            if nums[i] != 0:
                nums[j] = nums[i]
                j += 1
        print(i, j, count)
        while j<count:
            nums[j] = 0
            j += 1
```