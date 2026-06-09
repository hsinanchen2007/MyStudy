算法：
统计出每一年活多少人，然后找出最多人的最小值
```
class Solution(object):
    def maxAliveYear(self, birth, death):
        year=[]
        for i in range(0,101):
            year.append(0)
        for i in range(0,len(birth)):
            for j in range(birth[i]-1900,death[i]-1900+1):
                year[j]+=1
        max=0
        maxyear=0
        for i in range(99,0,-1):
            if year[i]>=max:
                max=year[i]
                maxyear=i
        return 1900+maxyear
```
