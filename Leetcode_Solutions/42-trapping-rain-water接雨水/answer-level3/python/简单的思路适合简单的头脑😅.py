### 解题思路
首先，max获得最大值，然后遍历到最大值之前，每次将此前最大值减去当前高度，并且不断更新此前最大值，跳出时根据当前坐标，反向遍历，再求一遍，完事。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if not len(height):
            return 0
        max_height=max(height)
        before_h=0
        count=0
        for i,h in enumerate(height):
            if h==max_height:
                break
            if h<before_h:
                count+=before_h-h
            elif h>before_h:
                before_h=max(h,before_h)
        before_h=0
        for h in height[i+1:][::-1]:
            if h<before_h:
                count+=before_h-h
            else:
                before_h=max(h,before_h)
        return count

                
```