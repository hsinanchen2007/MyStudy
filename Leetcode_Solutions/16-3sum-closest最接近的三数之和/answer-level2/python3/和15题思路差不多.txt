### 代码
```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        length = len(nums)
        nums.sort()

        res = nums[0] + nums[1] + nums[length - 1]
        difference = abs(res - target)

        i = 0
        while i < length - 2:
            j = i + 1
            k = length - 1

            # 逼近j,k
            while j < k:
                if nums[i] + nums[j] + nums[k] == target:
                    return target

                while j < k and nums[i] + nums[j] + nums[k] < target:
                    tempSum = nums[i] + nums[j] + nums[k]
                    tempDiff = abs(tempSum-target)
                    if tempDiff < difference:
                        res = tempSum
                        difference = tempDiff
                    j += 1
                    
                while j < k and nums[i] + nums[j] + nums[k] > target:
                    tempSum = nums[i] + nums[j] + nums[k]
                    tempDiff = abs(tempSum - target)
                    if tempDiff < difference:
                        res = tempSum
                        difference = tempDiff
                    k -= 1
                    
            i += 1

        return res



```
