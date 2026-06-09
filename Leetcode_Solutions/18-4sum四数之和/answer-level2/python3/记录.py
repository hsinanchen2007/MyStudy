```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:return []
        result = set()
        sumsIndexes = {}         
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] in sumsIndexes:
                    sumsIndexes[nums[i] + nums[j]].append((i, j))
                else:
                    sumsIndexes[nums[i] + nums[j]] = [(i, j)]
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                sumNeeded = target - (nums[i] + nums[j])
                if sumNeeded in sumsIndexes:
                    for index in sumsIndexes[sumNeeded]:                         
                        if index[0] > j:
                            result.add(tuple(sorted([nums[i], nums[j], nums[index[0]], nums[index[1]]])))
        result = [list(l) for l in result]
        return result 
```
