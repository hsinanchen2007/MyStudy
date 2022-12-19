# 视频
![盛最多的水 双指针.mp4](c2e70eca-204b-4c2c-a722-96df1f60d017)
# 代码
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # area = (right - left) * min(height[left], height[right])
        # 双指针，每次舍弃短板
        # 为什么？对于任意俩个左右板，指针靠近的过程中，底边长度一直再减小，如果高度减小，面积必然减小，则不可能存在更大的面积
        # 148ms
        left, right = 0, len(height)-1
        ma = 0
        while left < right:
            if height[left] < height[right]:
                area = (right - left)*height[left]
                left += 1
            else:
                area = (right - left)*height[right]
                right -= 1
            if area > ma:
                ma = area
        return ma
        
        # 暴力, TLE
        ma = 0
        N = len(height)
        for i in range(N):
            for j in range(i):
                ma = max(ma, (i-j)*min(height[i], height[j]))
        return ma
```
