第一步：从左往右遍历，在这一过程中如果始终没有比当前最高木板还要高的则会忽略
第二步：从右往左遍历，这一步主要是计算上一步中因为右边没有比最高木板高的木板而遗漏计算的雨水
```
class Solution:
    def trap(self, height: List[int]) -> int:
        sums = 0
        maxh = 0
        temp = 0
        maxindex = 0
        for i in range(len(height)):
            if height[i] >= maxh:
                maxindex = i
                sums += temp
                temp = 0
                maxh = height[i]
            temp += maxh - height[i]
        
        temp = 0
        maxh = 0
        for j in range(len(height)-1,maxindex-1,-1):
            if height[j] >= maxh:
                maxindex = j
                sums += temp
                temp = 0
                maxh = height[j]
            temp += maxh - height[j]
        return sums
```
