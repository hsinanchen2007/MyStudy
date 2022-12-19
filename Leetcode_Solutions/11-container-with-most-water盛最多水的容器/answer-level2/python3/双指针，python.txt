### 解题思路
双指针法

设置两个指针l和r，分别指向数组的开头和结尾

当height[l]<height[r]时，height[l]矮，左指针向后移动，l+=1,寻找更高的height[l],从而得到更大的maxarea

当height[l]>=height[r]时，height[r]矮，右指针向前移动，r-=1，寻找更高的height[r]，从而得到更大的maxarea

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxarea=0
        l = 0
        r = len(height)-1

        while(l<r):
            if height[l]<height[r]:
                area = (r-l) * height[l]
                
                l+=1
            else:
                area = (r-l) * height[r]
               
                r-=1
            maxarea = max(area,maxarea)
        return maxarea





```