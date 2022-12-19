指针法，p1表示第一个1的位置，p2表示第一个2的位置。
当遍历到的数为0时，将其放到已排序数组最前面，p1,p2都往后一位
当遍历到的数为1时，将其放到p1位置上并将之后的数往后移一位，p2往后一位
当遍历到的数为2时，不需要变化

```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p1 = 0 
        p2 = 0
        p3 = 0
        for p3 in range(len(nums)):
            if nums[p3] == 0:
                nums[1:p3+1] = nums[:p3]
                nums[0] = 0
                p1 += 1
                p2 += 1
            elif nums[p3] == 1:
                nums[p1+1:p3+1] = nums[p1:p3]
                nums[p1] = 1
                p2 += 1
        return nums
```
