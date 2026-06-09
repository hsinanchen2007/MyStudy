将圆在矩形的四边滚上一圈，圆心的轨迹为四条四分之一圆和四条边，简单的判断圆心是不是在这个范围就可以。

```
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 先将矩形移动到原点，圆也同步移动
        x_t = (x1+x2)/2
        y_t = (y1+y2)/2
        
        x_center -= x_t
        x1 -= x_t
        x2 -= x_t
        y_center -= y_t
        y1 -= y_t
        y2 -= y_t
        
        # 判断是否在上下两条边范围内
        if x1<=x_center<=x2 and y1-radius<=y_center<=y2+radius:
            return True
        
        # 判断是否在左右两条边范围内
        if x1-radius<=x_center<=x2+radius and y1<=y_center<=y2:
            return True
        
        # 判断是否在四个圆弧范围内
        if ((x1-x_center)**2+(y1-y_center)**2<=radius**2) or ((x1-x_center)**2+(y2-y_center)**2<=radius**2) or ((x2-x_center)**2+(y1-y_center)**2<=radius**2) or ((x2-x_center)**2+(y2-y_center)**2<=radius**2):
            return True
        
        
        return False
```
