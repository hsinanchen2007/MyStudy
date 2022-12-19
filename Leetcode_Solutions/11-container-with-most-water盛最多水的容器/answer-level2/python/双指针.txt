class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height)-1
        res = min(height[left], height[right])
        while left <right:
            temp = min(height[left], height[right]) * (right - left)
            if res < temp:
                res = temp            
            if height[left] <= height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
        return  res      