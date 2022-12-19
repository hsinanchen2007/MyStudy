### 解题思路
对比矩形中心之间的（X向和Y向）距离和矩形边长之和*1/2的大小，就能判断是否重合了。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        results= False 
        #确定rec1和rec2的中点及边长，（考虑到采用int比较省空间）将其同时放大两倍
        rec1_centerX=(rec1[2]+rec1[0])  #/2
        rec1_centerY=(rec1[3]+rec1[1])  #/2
        rec1_highX=(rec1[2]-rec1[0])    #/2
        rec1_highY=(rec1[3]-rec1[1])    #/2
        rec2_centerX=(rec2[2]+rec2[0])  #/2
        rec2_centerY=(rec2[3]+rec2[1])  #/2
        rec2_highX=(rec2[2]-rec2[0])    #/2
        rec2_highY=(rec2[3]-rec2[1])    #/2
        #如果中点（x和y）距离小于对应边之和则重合，否则不重合
        centerX=abs(rec1_centerX-rec2_centerX)
        centerY=abs(rec1_centerY-rec2_centerY)
        highX=abs(rec1_highX+rec2_highX)
        highY=abs(rec1_highY+rec2_highY)

        '''本来以为这样优化掉过程参数会优化的，结果内存没少，执行时间反而多了
        centerX=abs(rec1[2]+rec1[0]-rec2[2]-rec2[0])
        centerY=abs(rec1[3]+rec1[1]-rec2[3]-rec2[1])
        highX=abs(rec1[2]-rec1[0]+rec2[2]-rec2[0])
        highY=abs(rec1[3]-rec1[1]+rec2[3]-rec2[1])
        '''

        if centerX<highX and centerY<highY :
            results= True

        return results
```