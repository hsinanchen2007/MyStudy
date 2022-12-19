# 使用pop()弹出0
1. 倒序遍历数组
2. 遇0弹出添加到末尾
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(1,len(nums)+1):
            if nums[-i]==0:
                nums.append(nums.pop(-i))

```

