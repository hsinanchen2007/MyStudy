第一种，执行时间6604ms
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(length):
            for j in range(i+1,length):
                if nums[i] + nums[j] == target:
                    return [i,j]
```

第二种执行时间84ms，不过空间复杂度高

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, value in enumerate(nums):
            complement = target - value
            if complement in hashmap:
                return {hashmap[complement],index}
            hashmap[value] = index
```
