```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n1 = len(nums)
        result = []
        for i in nums:
            result.append([i])
        result2 = []
        while True:
            result1 = []
            for j in result:
                if j[-1] == nums[-1] or len(j) == n1:
                    continue
                else:
                    index1 = nums.index(j[-1])
                    for jj in range(index1+1,n1):
                        aa = j[:]
                        aa.append(nums[jj])
                        result1.append(aa)
            result2.extend(result)
            result = result1
            if result1 == []:
                result2.insert(0,[])
                return(result2)
```
