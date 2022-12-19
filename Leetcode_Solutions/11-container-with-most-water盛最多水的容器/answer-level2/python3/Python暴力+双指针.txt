# 暴力超时
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        maxArea = 0
        length = len(height)
        
        for i in range(length-1):
            iarea = []
            for j in range(i+1,length):
                maxArea = max(maxArea, min(height[i], height[j]) * (j-i))

        return maxArea
```
1. 暴力超时，时间复杂度On*n，空间复杂度O1
2. Java暴力不超时而python超时，因python为解释性语言，比java运行慢
3. 通过43/50个用例


# 双指针
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        l,r = 0,len(height)-1

        res = 0

        while(l < r):
            res = max(res, min(height[l], height[r]) * (r - l))
            if height[l] >  height[r]:
                r -= 1
            else:
                l += 1

        return res
```
1. 时间复杂度On，空间复杂度O1
