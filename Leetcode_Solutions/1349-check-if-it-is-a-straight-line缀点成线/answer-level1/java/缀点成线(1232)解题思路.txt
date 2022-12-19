### 解题思路
直线斜率 k = (y1 - y0) / (x1 - x0) = (y2 - y1) / (x2 - x1) 
为了避免除法，所以转化为乘法
(y1 - y0) * (x2 - x1) = (y2 - y1) * (x1 - x0)
只要两者不相等，即为三点不在一条直线上

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        for(int i = 2; i < coordinates.length ; i++)
        {
            int x0 = coordinates[i-2][0];
            int y0 = coordinates[i-2][1];
            int x1 = coordinates[i-1][0];
            int y1 = coordinates[i-1][1];
            int x2 = coordinates[i][0];
            int y2 = coordinates[i][1];
            if((y1 - y0) * (x2 - x1) != (y2 - y1) * (x1 - x0))
            {
                return false;
            }
        }
        return true;
    }
}
```