### 解题思路
1、找出圆圈和矩阵中重叠的x，y坐标
2、循环遍历查看它们与圆心的长度是否小于半径

### 代码

```java
class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int centerX1 = x_center - radius;
        int centerX2 = x_center + radius;
        int centerY1 = y_center - radius;
        int centerY2 = y_center + radius;

        if (x1 > centerX2 || x2 < centerX1 || y2 < centerY1 || y1 > centerY2) {
            return false;
        }
        int maxX1 = Math.max(centerX1, x1);
        int minX2 = Math.min(centerX2, x2);
        int maxY1 = Math.max(centerY1, y1);
        int minY2 = Math.min(centerY2, y2);

        for (int i = maxX1; i <= minX2; i++) {
            for (int j = maxY1; j <= minY2; j++) {
                if (Math.pow(Math.abs(i - x_center), 2) + Math.pow(Math.abs(j - y_center), 2) <= radius * radius) {
                    return true;
                }
            }
        }
        return false;
    }
}
```