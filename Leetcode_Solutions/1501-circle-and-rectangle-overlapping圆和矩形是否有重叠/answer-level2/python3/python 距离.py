先满足圆心与矩形心二次距离 在考虑横向距离与纵向距离
```
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        xc,yc = (x1+x2)/2,(y1+y2)/2
        x_l = (x2-x1)/2
        y_l = (y2-y1)/2
        if ((xc-x_center)**2+(yc-y_center)**2)**0.5<=radius+(x_l**2+y_l**2)**0.5:
            if abs(xc-x_center)<x_l+radius or abs(yc-y_center)<y_l+radius:
                return True
        return False
```
