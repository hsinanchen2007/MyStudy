### 解题思路
双指针法的应用，将指针设为左右两侧，若要寻得最大面积，则需要在宽度高度进行平衡，每次两边高度会取最小，而宽度则是二者位置之差，因为每次取最小高度，因此，若每次移动长的一侧，宽度缩小，高度则在上次的高度，与移动后的高度之间取最小值，如此则必然会减小，因此，每次指针移动高度较低的一边，直到两个指针相遇，每次记录最大的面积，得到结果

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        max_area = 0
        while(right>left):
            h = min(height[left],height[right])
            w = right-left
            max_area = max(max_area,h*w)
            if(height[left]<=height[right]):
                left+=1
            else:
                right-=1
        return max_area

```