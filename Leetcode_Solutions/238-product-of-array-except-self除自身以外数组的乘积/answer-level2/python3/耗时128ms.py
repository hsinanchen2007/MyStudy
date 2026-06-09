```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ji = 1
        result = []
        if 0 in nums:
            for k in nums:
                ji1 = 1
                list1 = nums[:]
                list1.remove(k)
                for kk in list1:
                    ji1 *= kk
                result.append(ji1)
            return(result)
        else:
            for i in nums:
                ji *= i

            for j in nums:
                result.append(int(ji/j))
            return(result)
```
