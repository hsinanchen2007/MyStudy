```
n = len(nums)
k = k%n
# nums[:n-k] = nums[:n-k][::-1]
# nums[n-k:] = nums[n-k:][::-1]
# nums[:] = nums[::-1]
# is same
# nums[:] = nums[::-1]
# nums[:k] = nums[:k][::-1]
# nums[k:] = nums[k:][::-1]
# is same
nums[:] = nums[n-k:] + nums[:n-k]
```
