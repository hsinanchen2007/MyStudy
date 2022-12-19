### 解题思路
如果遇到非0的，就依次放到数组前边并记录非0的数字出现次数
计算0的次数并把0放到数组的后边

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        tmp = 0
        for i,e in enumerate(nums):
            if e !=0:
                nums[tmp] = nums[i]
                tmp += 1
        c = len(nums)-tmp
        for j in range(c):
            nums[-(j+1)] = 0
```