思路：遍历数组，遇到0直接del删除并用append(0)在末尾添加0元素
```
class Solution:
    def moveZeroes(self, nums):
        l = len(nums)
        index = 0
        for i in range(l):
            if nums[index] == 0:
                del nums[index]
                nums.append(0)
                index-=1
            index+=1
```
