一、算法思想
1.遍历数组，并用哈希表计算每个数字出现的次数。
2.求哈希表中值得最大只，即为数组的度。
3.遍历字典，找出值等于数组的度的键，然后找出这些键在数组中最先和最后出现的位置i和j，则以i和j为首尾的子数组即为包含该键与nums拥有相同的度的连续子数组，找出由所有键得到的连续子数组的最小值，即为结果。
二、算法实现
```
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        d = {}
        for num in nums:
            d[num] = d.setdefault(num, 0) + 1
        du = max(d.values())
        if du == 1:
            return 1
        res = inf
        n = len(nums)
        for key, value in d.items():
            if value == du:
                i = 0
                while nums[i] != key:
                    i += 1
                j = n-1
                while nums[j] != key:
                    j -= 1
                if j - i + 1 < res:
                    res = j - i + 1
        return res 
```
三、复杂度分析
1.时间复杂度：O(N**2)。
2.空间复杂度：O(N)。
