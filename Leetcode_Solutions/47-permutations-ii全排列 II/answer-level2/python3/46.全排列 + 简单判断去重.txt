去重判断条件：` (nums[i] not in nums[first:i])`
```
def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            if first == n:
                results.append(nums[:])
                return 
            for i in range(first,n):
                if (i == first) or ((nums[i] != nums[first]) and (nums[i] not in nums[first:i])):
                    nums[i],nums[first] = nums[first],nums[i]
                    backtrack(first+1)
                    nums[i],nums[first] = nums[first],nums[i]
        n = len(nums)
        results = []
        backtrack()
        return results
```
