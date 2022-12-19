### 解题思路
Python3 非常愚蠢的解法。第一年和最后一年分开算，中间的直接算。上传上来给各位观众老爷一乐。

### 代码

```python3
from math import ceil
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        y1=int(date1[:4])
        y2=int(date2[:4])
        m1=int(date1[5:7])
        m2=int(date2[5:7])
        d1=int(date1[-2:])
        d2=int(date2[-2:])
        if (y1>y2) or (y1==y2 and m1>m2) or (y1==y2 and m1==m2 and d1>d2):
            y1,y2,m1,m2,d1,d2=y2,y1,m2,m1,d2,d1
        ms=[31,28,31,30,31,30,31,31,30,31,30,31]
        days=max(y2-y1-1,0)*(120+7*31+28)+ceil(max(y2-ceil((y1+1)/4)*4,0)/4)
        # print(max(y2-ceil((y1+1)/4)*4,0)//4)
        days1=0
        days2=0
        days1+=sum(ms[m1:])
        days1+=ms[m1-1]-d1
        if m1<=2 and not y1%4:
            days1+=1
        days2+=sum(ms[:m2-1])
        days2+=d2
        if m2>2 and not y2%4:
            days2+=1
        if y1==y2:
            days+=days1+days2-365
        else:
            days+=days1+days2
        # if (2000>y1 or(y1==2000 and m1<=2)) and (y2>2000 or (y2==2000 and m2>2)):
        #     days+=1
        if y2==2100 and m2>2:
            days-=1
        return days
```