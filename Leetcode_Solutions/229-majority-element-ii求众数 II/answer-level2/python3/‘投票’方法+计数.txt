**数组里面出现次数超过1/3的元素，即理每n/3个元素中至少有一个该元素，那么就可以遍历一边数组，相同元素value+1，直到threeTimes字典中keys到达n/3个，所有的value都减1，若value为0，移除该key。同时一个map记录所有元素的count，最后需过滤次数不到n/3的元素**

```python
class Solution:
    def handleMap(self,nums: {int: int}) -> {int: int}:
        res = {}
        for i in nums.keys():
            if len(nums) == len(nums) / 3:
                nums[i] = nums[i] - 1
            if nums[i] > 0:
                res[i] = nums[i]
        return nums

    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) < 3:
            return list(set(nums))
        
        threeTimes = {}
        allTimes = {}
        for item in nums:
            threeTimes = self.handleMap(threeTimes)
            if item in threeTimes.keys():                
                threeTimes[item] += 1
            else:
                threeTimes[item] = 1

            if item in allTimes.keys():
                allTimes[item] += 1
            else:                
                allTimes[item] = 1
            
        if len(threeTimes) == 0:
            return []

        res = []
        for key in threeTimes.keys():
            if allTimes[key] > len(nums) / 3:
                res.append(key)

        return res
```
