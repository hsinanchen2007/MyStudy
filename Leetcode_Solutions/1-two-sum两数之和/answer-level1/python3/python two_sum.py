
```
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #方法一：暴力求解，时间复杂度O(n2)
        for each1 in range(len(nums)):
            for each2 in range(each1+1,len(nums)):
                if nums[each1] + nums[each2] == target:
                   return [each1,each2]
        return 0

        #方法二：利用字典直接索引结果,时间复杂度O(n)
        hash = {}
        for each in range(len(nums)):
            if target-nums[each] in hash:
                return [hash[target-nums[each]],each]
            else:
                hash[nums[each]] = each
        return 0
```

