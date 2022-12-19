这道题可以使用两个数组来分别保存每个索引前面数字的和与后面数字的和，然后从前往后遍历找到这两个数组第一个相等元素的索引即可。  
```Python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        dp1 = [0] * n
        dp2 = [0] * n
        for i in range(1,n):
            dp1[i] = dp1[i-1] + nums[i-1]
            dp2[n-1-i] = dp2[n-i] + nums[n-i]
        for i in range(n):
            if dp1[i] == dp2[i]:
                return i
        return -1
```