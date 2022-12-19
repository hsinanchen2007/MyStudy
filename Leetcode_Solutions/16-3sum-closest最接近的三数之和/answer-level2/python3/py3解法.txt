```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        best = nums[0] + nums[1] + nums[2]
        
        for num1 in range(len(nums)-2):
            num2,num3 = num1+1, len(nums)-1
            
            while(num2 != num3):
                thisSum = nums[num1]+nums[num2]+nums[num3]
                if thisSum == target:
                    return thisSum
                elif thisSum < target:
                    num2 += 1
                elif thisSum > target:
                    num3 -= 1
                if abs(thisSum-target) < abs(best-target):
                    best = thisSum
        return best
```
