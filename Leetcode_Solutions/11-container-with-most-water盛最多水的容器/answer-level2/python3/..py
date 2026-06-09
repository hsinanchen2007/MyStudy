### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        locate = {i : height[i] for i in range(len(height))}
        l = 0
        r = len(locate) - 1
        locate_r = [r]
        locate_l = [l]            
        for i in range(len(locate)):
            if locate[i] > locate[locate_l[-1]]:
                locate_l.append(i)
            if locate[r-i] > locate[locate_r[-1]]:
                locate_r.append(r-i)
        area = (r - l) * (min(locate[l],locate[r]))

        for l in locate_l:
            for r0 in locate_r:
                if r0 > l and min(locate[l],locate[r0])*(r0 - l) > area:
                    area = min(locate[l],locate[r0])*(r0 - l)
        return area
```