### 解题思路
我们先统一坐标系，以矩形中心为原点，把圆统一到第一象限。圆的分布有下面3种情况。1、圆心在矩形右边界的右边且纵坐标小于矩形上边界,直接判断圆心到矩形右边界距离是否小于半径。2、圆心在矩形右边界左边，且纵坐标大于上边界，直接判断圆心到矩形上边界距离是否小于半径。3、圆心在矩形右边界右边且在上边界上面，那么就计算圆心到矩形右上角端点的距离是否小于半径。
![v2-893862b74c483fe8cda78599e42e634e_1440w.png](https://pic.leetcode-cn.com/75294b6dc816c750b71e283c1830d5f9490db906260e256810f8b295ab3d508c-v2-893862b74c483fe8cda78599e42e634e_1440w.png)


### 代码

```python3
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        c_x = (x1+x2)/2
        c_y = (y1+y2)/2
        
        #转第一象限
        p_x = abs(c_x-x_center)
        p_y = abs(c_y-y_center)
        
        h_x = (x2-x1)/2
        h_y = (y2-y1)/2
        
        a = p_x-h_x
        b = p_y-h_y
        
        if a<=0 and b<=0:
            return True
        
        if a<=0:
            return b<=radius
        if b<=0:
            return a<=radius
        
        return a**2+b**2 <= radius**2
```