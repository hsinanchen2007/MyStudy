解题思路：暴力法全举子数组和，时间复杂度O(n ^ 2)
哈希法，时间复杂度O(n), 空间复杂度O(n)
第一步：使用字段存储，K=每个位置的累积和，V=累积和出现的次数
第二步：计算res，查看sum - k 是否存在字典里；如果存在 res += dic[sum - k]
特殊情况 k == 0 时，res -= 1(因为k = 0时，sum - k == sum, 而dic[sum]总会加一)
```
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dic = dict()
        dic[0] = 1
        res = 0
        sum = 0

        for i in range(len(nums)):
            sum += nums[i]

            if sum not in dic:
                dic[sum] = 1
            else:
                dic[sum] += 1

            if sum - k in dic:
                res += dic[sum - k]
                if k == 0:
                    res -= 1

        return res
```
