
计算面积的逻辑也很简单，这个算法一般应用于目标检测里计算两个anchor交并比（iou）时使用

```
def isRectangleOverlap(rec1, rec2) -> bool:
    x1,y1,x2,y2 = rec1[0],rec1[1],rec1[2],rec1[3]
    _x1,_y1,_x2,_y2 = rec2[0],rec2[1],rec2[2],rec2[3]
    if x2 <= _x1 or _x2 <= x1 or y2 <= _y1 or _y2 <= y1:
        return False
    else:
        x_left = max(x1, _x1)
        x_right = min(x2, _x2)
        y_top = min(y2, _y2)
        y_bottom = max(y1, _y1)
        area = (x_right - x_left) * (y_top - y_bottom)
        print(area)     # 这里面积也算出来了
        return (area > 0)
```

