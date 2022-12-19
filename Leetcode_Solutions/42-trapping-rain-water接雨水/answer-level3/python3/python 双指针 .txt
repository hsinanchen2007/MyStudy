### 解题思路
时间复杂度o(n),空间o(1)
双指指向两侧，我们只关注左右两边最大值 较小的那一侧，如果左边较小，答案只存在于左边，res+=左边最大值-当前高度，并且更新左边最大值。
反之亦然

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        res=0
        n=len(height)
        left=0
        right=n-1
        leftMax=height[0]
        rightMax=height[-1]
        while left<=right:
            leftMax=max(leftMax,height[left])
            rightMax=max(rightMax,height[right])
            if leftMax<rightMax:
                res+=leftMax-height[left]
                left+=1
            else:
                res+=rightMax-height[right]
                right-=1
        return res



       
```