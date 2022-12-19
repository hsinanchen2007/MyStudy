### 解题思路
只要满足**每个矩形左下角的点均位于另一个矩形的左下方**(不包括上边和右边的边界所在直线)即可满足题意

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        #右上角的点坐标一定都大于左下角坐标
        x1,y1,x2,y2 = rec1[0],rec1[1],rec1[2],rec1[3]
        a1,b1,a2,b2 = rec2[0],rec2[1],rec2[2],rec2[3]
        if x1 < a2 and y1 < b2 and a1 < x2 and b1 < y2:
            return True
        else:
            return False 
```