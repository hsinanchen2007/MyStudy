```
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if points==[]:
            return 0
        if len(points)==1:
            return 1
        if points==[points[0]]*len(points):
            return len(points)
        lines=[]
        for i in range(len(points)-1):
            for j in range(i+1,len(points)):
                p1=points[i]
                p2=points[j]
                if p1!=p2:
                    lines.append(p1+[p2[0]-p1[0],p2[1]-p1[1]])
        # print(lines)
        res=0
        for line in lines:
            temp=0
            for p in points:
                if (p[1]-line[1])*line[2]-(p[0]-line[0])*line[3]==0:
                    temp+=1
            res=max(res,temp)

        return res
```

最开始，我根据直线斜率k和截距b组成的字符串str(k)+'#'+str(b)来表示直线，将该字符串作为字典的键；得出了所有的直线之后，再将每个点的坐标（x,y）代入进去，判断k*x+b是否等于0从而判断点是否在该直线上，但是遇到了浮点数的精度问题；而这主要是由于计算k的时候用了除法。

后来，我换了个方式，不再用k和b来表示一条直线，而是用直线上一点和直线的方向向量来表示；对于点P1(x1,y1)、P2(x2,y2)，他们俩确定的直线用[x1,y1,x2-x1,y2-y1]来表示；确定完所有的直线后，对于每一个点（x0,y0），判断(y0-y1)*(x2-x1)-(x0-x1)*(y2-y1)是否等于0，总而判断点是否在该直线上；这是向量知识。进而可以统计出在每条直线上的点的数目。
