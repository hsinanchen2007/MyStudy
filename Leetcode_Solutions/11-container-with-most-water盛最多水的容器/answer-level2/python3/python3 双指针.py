### 解题思路
左侧=height[0],右侧=height[-1]
容量取决于左右两侧较小的那一边，如果左边较小，右侧怎么移动，都不会大于当前的值，所以当左侧的高度小于右侧时，left+=1
反之，right-=1

### 代码

```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxV=0
        left,right=0,len(height)-1
        while left<right:
            maxV=max((right-left)*min(height[left],height[right]),maxV)
            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return maxV

```
