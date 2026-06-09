![image.png](https://pic.leetcode-cn.com/74691da2f2e0c8222ad0ea45ae73ab5e38551cdcdf37493f05593f54fa94fb1e-image.png)

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):

        n = len(nums)
        first = {}
        for i in range(n):
            if nums[i] in first:
                if i - first[nums[i]] <= k:
                    return True
                first[nums[i]] = i
            else:
                first[nums[i]] = i
        return False