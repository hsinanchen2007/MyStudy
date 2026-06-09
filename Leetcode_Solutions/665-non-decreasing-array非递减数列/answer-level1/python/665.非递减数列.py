### 解题思路
分析题目：当出现nums[i-1]>nums[i]时，改变nums[i-1] or nums[i]，可以使数列只通过一次变成非递减。
方案：因为从前往后遍历，使nums[i-1] = nums[i]可以不干扰后面的结果。
一种例外情况:如果nums[i-1]>nums[i-2]>nums[i],只能使nums[i]=nums[i-1]
count记录变化次数，i从1开始遍历不然out of range

### 代码
```python
class Solution(object):
    def checkPossibility(self, nums):
        count = 0
        for i in range(1,len(nums)):
            if nums[i-1] > nums[i]:
                if i-2 >= 0:
                    if nums[i-2] <= nums[i]:
                        nums[i-1] = nums[i]
                    else:
                        nums[i] = nums[i-1]
                else:
                    nums[i-1] = nums[i]
                count += 1
        return count <= 1
```