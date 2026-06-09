```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #利用字典的方法 时间复杂度O(n) 空间复杂度O(n)
        result = []
        m = collections.Counter(nums)
        for key, val in m.items():
            if val > (len(nums) // 3):
                result.append(key)
        return result
        if not nums:
            return None
        # 摩尔投票法 时间复杂度O(n) 空间复杂度O(1)
        m,n = nums[0], nums[0]
        count_m, count_n = 0, 0
        for i in nums:
            if m == i:
                count_m += 1
            elif n == i:
                count_n += 1
            elif not count_m:
                m, count_m = i, 1
            elif not count_n:
                n, count_n = i, 1
            else:
                count_m -= 1
                count_n -= 1
        count_m, count_n = 0, 0
        result = []
        for temp in nums:
            if m == temp:
                count_m += 1
            elif n == temp:
                count_n += 1
        if count_n > len(nums) // 3:
            result.append(n)
        if count_m > len(nums) // 3:
            result.append(m)
        return result
```
