1. O(n)空间复杂度

```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l2r,r2l = [1] * (len(nums) + 1),[1] * (len(nums) + 1)

        for i in range(len(nums)):l2r[i+1] = l2r[i] * nums[i]
        for i in range(len(nums)-1,-1,-1):r2l[i] = r2l[i+1]* nums[i]

        results = []
        for i in range(len(nums)):results.append(l2r[i]*r2l[i+1])
        return results
```

2. O(1)空间复杂度

题目说明：出于对空间复杂度分析的目的，输出数组不被视为额外空间。
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results = []
        left,right = 1,1
        for i in range(len(nums)):
            results.append(left)
            left *= nums[i]
        for i in range(len(nums)-1,-1,-1):
            results[i] = results[i] * right
            right *= nums[i]
        return results
```
![image.png](https://pic.leetcode-cn.com/6e04f3ac868c97d8dc131feff7fcc13d3a07f71d5e15375ca48fd46361331886-image.png)

