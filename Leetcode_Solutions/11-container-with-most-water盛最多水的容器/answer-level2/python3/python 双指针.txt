class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        i = 0
        j = len(height)-1
        m = min(height[i],height[j])*(j-i)
        while(i<j):
            if(height[i]<height[j]):
                i+=1
                m = max(m,min(height[i],height[j])*(j-i))
            else:
                j-=1
                m = max(m,min(height[i],height[j])*(j-i))
                    
        return m