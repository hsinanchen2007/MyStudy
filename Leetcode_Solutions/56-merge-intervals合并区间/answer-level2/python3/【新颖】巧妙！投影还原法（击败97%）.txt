![图片1.png](https://pic.leetcode-cn.com/eb9dc635a00c44a791ef19fa51577cc42cc7603cbf455aa7db5ff5118ed4bf4a-%E5%9B%BE%E7%89%871.png)

![搜狗截图20年01月18日2332_1.png](https://pic.leetcode-cn.com/30c10a7b7b136e341e1eb32cd5f649dc5c2d2d9388fe69e033a7984c514929cb-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B401%E6%9C%8818%E6%97%A52332_1.png)
时间：击败97%
空间：击败100%

算法思想主体：先不考虑“单点”（如[2,2]）的情况：

0.整体思想：如同线段集合在一维空间上的投影！只要某数出现一次就当会存在
1.每段线段用中间点表示，如区间[1,5]表示为mid_point=[1.5,2.5,3.5,4.5]（及一个x代表(x-0.5)~(x+0.5)区间）
2.将输入中的所有遍历一遍，构成无重复（可以用集合完成）的mid_point，并排序
3.将mid_point还原成最终的区间（判断下一个mid_point是否与已存在的区间差0.5，是则合成一个，否则新建立一个）

注意：本题需考虑多个“单点”，因此需要在上述主体上进行补充，具体见代码

```
class Solution:
    def merge(self, intervals):
        mid_point = set()
        res=[]
        point=set()#存所有的单点
        for i in intervals:
            if i[0]==i[1]:point.add(i[0])
            else:
                for j in range(i[0],i[1]):
                    mid_point.add(j+0.5)
        mid_point=sorted(list(mid_point))
        point=sorted(list(point))
        #一个点代表一个长度为1的线段
        if mid_point:
            while len(point)!=0:
                if point[0]<int(mid_point[0]-0.5):
                    res.append([point[0],point[0]])
                    del point[0]
                else:break
        else:
            while len(point)!=0:
                res.append([point[0],point[0]])
                del point[0]
            return res
        for i in mid_point:
            if len(res)==0 or res[-1][1]+0.5!=i: res.append([int(i-0.5),int(i+0.5)])
            else: res[-1][1]=int(i+0.5)
            while len(point)!=0:
                
                if point[0]>res[-1][1]:break
                elif point[0]>=res[-1][0] and point[0]<=res[-1][1]:del point[0]
                else:
                    temp=res[-1]
                    del res[-1]
                    res.append([point[0],point[0]])
                    res.append(temp)
                    del point[0]
        while len(point)!=0:
            if point[0]>=res[-1][0] and point[0]<=res[-1][1]:del point[0]
            else:
                res.append([point[0],point[0]])
                del point[0]
        return res
```
