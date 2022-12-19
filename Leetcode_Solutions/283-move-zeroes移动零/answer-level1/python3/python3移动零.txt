### 解题思路
把所有非零元素移到前面，后面补上0即可。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j] = nums[i]
                j += 1
        for k in range(j,len(nums)):
            nums[k]=0
```

![image.png](https://pic.leetcode-cn.com/729ab219f8e3d097da2937bcb0b383a256cb670c02bb383760b67283c0227e7a-image.png)
