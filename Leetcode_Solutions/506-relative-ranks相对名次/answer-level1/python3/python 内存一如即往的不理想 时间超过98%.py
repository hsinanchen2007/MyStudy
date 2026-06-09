一开始准备直接利用获取原nums的索引进行替换，发现有点慢(难道是获取索引的过程慢么。。)。。然后用字典保存值与对应的名次再遍历nums一一替换。

```
class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        new_nums, dic = sorted(nums, reverse=True), {}

        for index, value in enumerate(new_nums):
            if index == 0:
                dic[value] = "Gold Medal"
            elif index == 1:
                dic[value] = "Silver Medal"
            elif index == 2:
                dic[value] = "Bronze Medal"
            else:
                dic[value] = str(index+1)
        for i in range(len(nums)):
            nums[i] = dic.get(nums[i])
        return nums
```
原做法：
```
class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        new_nums = sorted(nums, reverse=True)

        for index, value in enumerate(new_nums):
            if index == 0:
                nums[nums.index(value)] = "Gold Medal"
            elif index == 1:
                nums[nums.index(value)] = "Silver Medal"
            elif index == 2:
                nums[nums.index(value)] = "Bronze Medal"
            else:
                nums[nums.index(value)] = str(index+1)
        return nums
```
