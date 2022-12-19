### 思路：有点抖机灵了，全靠Python的内置函数
1、只要当前是0，就移除，同时在末尾在加上一个0。
2、结束
### 代码：
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if nums[i]==0:
                nums.remove(0)
                nums.append(0)
```
