```
// 计算矩形上的每个点到圆心的距离是否大于等于圆的半径
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            float distance = sqrt((i - x_center) * (i - x_center) + (j - y_center) * (j - y_center));
            if(distance <= radius) {
                return true;
            }
        }
    }
    
    return false;
}

```
