class Solution:
    def trap(self, height):
        if not height:
            return 0
        ret =0
        left_high=height[0]
        right_high=None
        for i in  range(len(height)):
            if i==0 or i==len(height)-1:continue
            if not right_high:right_high=max(height[i+1:]) #初始化右边积木最大值
           # print('i',i,'left_high',left_high,'right_high',right_high)
            lower_heigh  = min(left_high,right_high)
            if height[i]<lower_heigh:ret+=lower_heigh-height[i]
            if height[i]>=left_high:left_high=height[i]
            if height[i]>=right_high:right_high=max(height[i+1:])
        return ret