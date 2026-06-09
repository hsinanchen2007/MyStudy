###### 1、建立(值, 索引)后根据值排序
###### 2、根据排序结果确定名次
```
class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        count = len(nums)
        new_nums = []
        for index in range(count):
            new_nums.append((nums[index], index))  # (成绩, 索引)
        new_nums.sort(key=lambda v: v[0], reverse=True)
        try:
            nums[new_nums[0][1]] = 'Gold Medal'
            nums[new_nums[1][1]] = 'Silver Medal'
            nums[new_nums[2][1]] = 'Bronze Medal'
        except:
            return nums
        else:
            for index, new_num in enumerate(new_nums[3:], 3):
                nums[new_num[1]] = str(index+1)
            return nums
```
