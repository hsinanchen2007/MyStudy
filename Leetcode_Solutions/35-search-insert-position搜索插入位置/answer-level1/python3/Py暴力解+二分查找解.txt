首先是暴力解法```
       for i in range(len(nums)):
           if nums[i] == target:
               return i
           elif nums[i] > target:
               return i
       return len(nums)
```
没什么好说的，找到目标了就返回下标。
如果查到这个数大于目标了，那应该在这个数的位置插入，也返回下标。
都没找到，说明应该在最后插入，返回长度。

接下来是二分查找的解法，最后的思路同上，主要是查找过程使用了二分查找的办法。
```
       left = 0
       right = len(nums) - 1
        while left <= right:
            if nums[int ((left+right)/2)]  > target:
                right = int ((left+right)/2) - 1
            elif nums[int ((left+right)/2)]  < target:
                left = int ((left+right)/2) + 1
            else:
                return int ((left+right)/2)
       return left
```
分成左右两部分，左边小右边大。当中间比目标值大时，说明应该到左边去找，故把右边的边界左移。
比目标值小时思路类似，右移左边边界。
