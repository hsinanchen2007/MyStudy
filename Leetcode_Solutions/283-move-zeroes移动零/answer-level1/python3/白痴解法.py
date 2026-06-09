### 解题思路
双指针
将非0值往前移
i：非0值要移动到的目标位置
j：寻找非0值
count：记录有多少0值

最后在数组末尾加上count个0即可

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i = 0
        j = 0
        count = 0
        while j < len(nums):
            if nums[j] != 0:
                nums[i] = nums[j]
                i += 1
                j += 1
            else:
                count += 1
                j += 1
        for i in range(len(nums)-1, len(nums)-1-count, -1):
            nums[i] = 0
        return nums
```