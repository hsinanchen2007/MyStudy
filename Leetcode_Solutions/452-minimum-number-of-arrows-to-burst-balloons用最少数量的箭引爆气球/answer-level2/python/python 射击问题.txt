### 解题思路
1.先排序，按照第一个元素
2.设置shoot_begin,shoot_end,重叠区间，从point[0]开始
3.相邻两个区间有重叠就更新重叠区间，shooter数不变
4.没有shooter加一，更新shoot_begin,shoot_end


### 代码

```python
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points)==0:
            return 0
        points=sorted(points,key=lambda s:s[0])
        shooter=1
        shoot_begin=points[0][0]
        shoot_end=points[0][1]
        i=1
        while(i<=len(points)-1):
            if(points[i][0]>shoot_end):
                shooter+=1
                shoot_begin=points[i][0]
                shoot_end=points[i][1]
                i+=1
            else:
                shoot_begin=points[i][0]
                if(shoot_end>points[i][1]):
                    shoot_end=points[i][1]
                i+=1
        return shooter
        



```