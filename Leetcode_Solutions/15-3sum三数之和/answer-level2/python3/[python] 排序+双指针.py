1. 先对数组num进行排序
2. 需要满足nums[i]+nums[j]+nums[k]=0，即nums[j]+nums[k]=-nums[i]
3. nums[i] 从左到右遍历数组，左指针left=i+1, 右指针right=len(nums)-1
    if nums[left]+num[right]<-nums[i]
        left+=1
    elif nums[left]+num[right]>-nums[i]:
        right-=1
    else:
        if [-now, num_left, num_right] not in res:
            res.append([now, num_left, num_right])
        left+=1
        right-=1

```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        for n in range(len(nums)):
            now = - nums[n]
            left = n + 1
            right = len(nums) - 1
            while left < right:
                num_left = nums[left]
                num_right = nums[right]
                if num_left + num_right < now:
                    left += 1
                elif num_left + num_right > now:
                    right -= 1
                else:
                    if [-now, num_left, num_right] not in res:
                        res.append([-now, num_left, num_right])
                    left += 1
                    right -= 1
        return res
```
