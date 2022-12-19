解法一：创建一个字典，遍历原数组，原数组的数作为字典的键，每个数出现的次数作为字典的值，输出次数大于1的数字
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dicts = {}  # 以nums里的数字作为键key，数字出现的次数作为值value
        for i in nums:
            if i in dicts:
                dicts[i] += 1
            else:
                dicts[i] = 1
            if dicts[i]>1:
                return i
```
解法二：先用sort()对数组进行排序，之后按顺序遍历数组，遇到相同的值则返回
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(0,len(nums)+1):
            if nums[i]==nums[i+1]:
                return nums[i]
```
解法三：创建一个新的数组，遍历原数组，将得到的值作为新数组的下标，每遍历一个新的数，对应新的数组中，下标为该数的值加一，返回新数组中大于1的数的下标
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        arr = [0]*len(nums)
        for i in range(len(nums)):
            arr[nums[i]] += 1
            if arr[nums[i]] > 1:
                return nums[i]
```