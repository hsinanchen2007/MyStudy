```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return 0
        flag = 0
        for i in nums:
            if flag == 0:
                repeat_num = i
                flag = 1
            elif i == repeat_num:
                flag += 1
            else :
                flag -= 1
        return repeat_num
        
        
```
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = collections.Counter(nums)
        for val,times in dic.items():
            if times > len(nums)/2 :
                return val
        
```
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[int(len(nums)/2)]
```
