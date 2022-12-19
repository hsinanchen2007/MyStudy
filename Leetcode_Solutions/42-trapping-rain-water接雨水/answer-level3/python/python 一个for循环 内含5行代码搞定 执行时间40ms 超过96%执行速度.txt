```
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
# 整体思想，遍历每个柱子，求每个柱子接水量，之后求和
        if len(height) < 2:  #少于两个柱子，直接返回0
            return 0
        total = 0  #记录总接水量
        left = 0 #记录左边最高柱子
        right = max(height) #记录右边最高柱子
        
        for i in range(len(height)):
            
            left = max(left,height[i])
            if height[i] == right and i != len(height)-1: 
                right = max(height[i+1:])
          
            #计算每个柱子水量
            if height[i] < min(left, right):
                total += min(left, right) - height[i]
                #print total,i
        return total
```
