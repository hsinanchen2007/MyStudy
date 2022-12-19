类似于动态规划思想，一次遍历，每一步的中间变量表示当前位置的最大正值和负值，对长度大于1的结果必定是大于0的，所有当当前位置连续乘积最大值小于0或最小值大于0时都令成0即可，比较res和当前最大正值即可。
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        mid = [0,0]
        if nums[0] >= 0:
            mid = [0,nums[0]]
        else:
            mid = [nums[0],0]
        for i in range(1,len(nums)):
            if nums[i] >= 0:
                mid[1] = max(nums[i],nums[i]*mid[1])
                mid[0] = mid[0]*nums[i]
            else:
                mid[0],mid[1] = min(nums[i],nums[i]*mid[1]), nums[i]*mid[0]
            res = max(res,mid[1])
        return res
```


