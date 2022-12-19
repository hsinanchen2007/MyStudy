
直接上代码，详见博客——https://blog.csdn.net/TeFuirnever/article/details/94444437
```py
class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = list()
        nums.sort()
        for i, m in enumerate(nums[0:-2]):
            l, r = i + 1, len(nums) - 1
            if nums[l] + nums[l+1] + m > target:
                result.append(nums[l] + nums[l+1] + m)
            elif nums[r] + nums[r-1] + m < target:
                result.append(nums[r] + nums[r-1] + m)
            else:
                while l < r:
                    result.append(nums[l] + nums[r] + m)
                    if nums[l] + nums[r] + m < target:
                        l += 1
                    elif nums[l] + nums[r] + m >target:
                        r -= 1
                    else:
                        return target
        result.sort(key=lambda x:abs(x-target))
        return result[0]
```


