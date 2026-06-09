### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        maxl=[0]*n
        maxr=[0]*n
        if len(height)<2:
            return 0
        maxl[0],maxr[-1]=height[0],height[-1]
        for i in range(1,n):
            maxl[i] = max(maxl[i-1],height[i])###maxl[i-1]存着height[0-i]中的最大值，如果height[i]比左边都大，则maxl[i]更新为height[i]
            
        for i in range(n-2,-1,-1):
            maxr[i] = max(maxr[i+1],height[i])###maxr[i+1]存着height[i-n]中的最大值，如果height[i]比右边都大，则maxr[i]更新为height[i]
            
        res = 0
        for i in range(n):
            res += min(maxr[i],maxl[i])-height[i]
        return res


```