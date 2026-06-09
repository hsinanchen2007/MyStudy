### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # 去重
        if len(points)<3:
            return len(points)
        points = sorted(points)
        cnt, xy, points = [], points, []
        for i in range(len(xy)):
            if i>0 and xy[i][0]==xy[i-1][0] and xy[i][1]==xy[i-1][1]:
                cnt[len(points)-1]+=1
            else:
                cnt.append(1)
                points.append(xy[i])

        n, maxLen = len(points), 2
        if n==1: return cnt[0]
        if n==2: return cnt[0]+cnt[1]
        MAX=1000000
        maxLen = 0
        # y轴共线， 有斜率
        for i in range(len(points)):
            x, tab = cnt[i], {}
            for j in range(i+1, len(points)):
                if points[j][0]==points[i][0]:
                    x += cnt[j]
                else:
                    k = (points[j][1]-points[i][1])*MAX/(points[j][0]-points[i][0])
                    if k in tab:
                        tab[k]+=cnt[j]
                    else:
                        tab[k] = cnt[i] + cnt[j]
            maxLen = max(maxLen, x)
            if tab: maxLen= max(maxLen, max(tab.values()))
        return maxLen
```