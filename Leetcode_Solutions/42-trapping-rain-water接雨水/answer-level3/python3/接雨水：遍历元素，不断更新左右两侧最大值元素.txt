### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRightV(self, j0, height): # 更新右侧最大值及索引
        rightv, ri = height[j0], j0
        for j in range(j0+1,len(height)):
            if height[j]>=rightv:
                rightv = height[j]
                ri = j
        return rightv, ri
    def trap(self, height: List[int]) -> int:
        if len(height)<3:
            return 0
        sumv = 0
        leftv, li = height[0], 0
        rightv, ri = self.findRightV(2, height)
        for i in range(1, len(height)-1):
            # 累加当前元素水量
            if ri>i and height[i] < min(leftv, rightv):
                sumv += min(leftv, rightv)-height[i]
            # 更新左侧最大值
            leftv = max(leftv, height[i])
            # 更新右侧最大值
            if ri == i+1 and i+2<len(height):
                rightv, ri = self.findRightV(i+2, height)
        return sumv

```
最差情况时间复杂度O(N^2)
