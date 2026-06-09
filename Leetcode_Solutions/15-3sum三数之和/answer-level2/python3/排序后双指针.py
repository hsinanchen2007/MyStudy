没想出这个用set应该怎么处理重复的数字以达到O(n2)级别，这个是先排序然后双指针相夹来找到确定和的
```
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        length = len(nums)
        redata = []
        for i in range(length-2):
            # 相同元素只在第一次出现的时候操作一次
            if nums[i] == nums[i-1] and i > 0: continue
            j = i+1 #左指针
            k = length-1 #右指针
            suit = 0 - nums[i]
            while j < k:
                if nums[j] + nums[k] == suit:
                    redata.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while nums[j-1] == nums[j] and j < k: j += 1
                    while nums[k+1] == nums[k] and j < k: k -= 1
                elif nums[j] + nums[k] < suit:
                    j += 1
                    while nums[j - 1] == nums[j] and j < k: j += 1
                elif nums[j] + nums[k] > suit:
                    k -= 1
                    while nums[k + 1] == nums[k] and j < k: k -= 1
        return redata
```
