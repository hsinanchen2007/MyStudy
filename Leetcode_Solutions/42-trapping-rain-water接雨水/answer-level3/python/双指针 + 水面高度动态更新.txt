核心思路： 
    若坐标i和j中的较小高度为h，那么任何k 满足 i<k<j 如果k的高度hk小于h则地k位至少能盛水h-hk
    双指针向中间逼近，不断更新h值，保证求的坐标的盛水量是最大的。
代码：
```
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right, area, high = 0, len(height)-1, 0 , 0
        while left < right:
            if height[left] <= height[right]:
                if height[left] > high:
                    high = height[left]
                if high > height[left+1]:
                    area += (high - height[left+1])
                left += 1
            else:
                if high < height[right]:
                    high = height[right]
                if high > height[right-1]:
                    area += (high - height[right-1])
                right -= 1
                
        return area
```
