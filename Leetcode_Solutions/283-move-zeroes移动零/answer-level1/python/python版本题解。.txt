
方法一
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeroList = []
        for i in range(0, len(nums)):
            if nums[i] == 0:
                zeroList.append(i)
        for i in range(0, len(zeroList)):
            del nums[zeroList[i] - i]
        for i in range(0, len(zeroList)):
            nums.append(0)
```
方法一没有优化，纯逻辑代码，遍历找出0的下标，删除and添加。

方法二
``` python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pointZero = 0
        for i in range(0, len(nums)):
            if nums[i] != 0:
                if nums[pointZero] == 0:
                    nums[pointZero],nums[i] = nums[i],nums[pointZero]
                pointZero += 1
```
方法二则是减少空间占用，用指针记录0的位置，遍历找到非零的就交换，i只要不指向0，指针就往下挪动。一次循环即可。注意，永远是先增加指针，后增长i。
