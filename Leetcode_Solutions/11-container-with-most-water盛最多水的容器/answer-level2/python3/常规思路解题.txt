### 解题思路
此处撰写解题思路
要保证水量最大，则满足两个条件，底最宽，高最长，则可以从最宽的底开始搜索，一次探索最宽的底可以使用的最长的高，如此循环即可，详见代码。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        right=len(height)-1
        left=0
        tmp=0
        while right>left:
            tmp=max(tmp,min(height[left],height[right])*(right-left))
            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return tmp

        
```