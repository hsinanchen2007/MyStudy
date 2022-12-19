### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if not rec1 or not rec2 :
            return False
        #以x1坐标更小的矩形为基准：
        if rec1[0]<=rec2[0]:
            x1,y1,x2,y2 = rec1[0],rec1[1],rec1[2],rec1[3]
            x3,y3,x4,y4 = rec2[0],rec2[1],rec2[2],rec2[3]
        else:
            x1,y1,x2,y2 = rec2[0],rec2[1],rec2[2],rec2[3]
            x3,y3,x4,y4 = rec1[0],rec1[1],rec1[2],rec1[3]
        #此时，x1,yi,x2,y2这个矩阵更左
        ##此时不重叠有以下几种情形，第一，靠右矩阵的整体在左矩阵上方y3>= y4，第二，下方 y4 <=y1 ,第三右方
        if y3>= y2 or y4 <=y1 or x3>=x2:
            return False
        return True



  

```