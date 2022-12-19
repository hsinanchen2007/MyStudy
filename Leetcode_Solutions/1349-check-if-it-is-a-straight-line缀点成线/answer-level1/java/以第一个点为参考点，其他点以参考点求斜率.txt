### 解题思路
- 求出第1个点与第2个点之间的斜率
- 求第3....n个点与第一个点之间的斜率
- 为了消除分母为零的影响，该为乘积方式，乘积不为0，返回false

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
         int x1 =coordinates[1][0]-coordinates[0][0];
        int y1 =coordinates[1][1]-coordinates[0][1];
        for (int i = 2; i < coordinates.length; i++) {
            int x2 =coordinates[i][0]-coordinates[0][0];
            int y2 =coordinates[i][1]-coordinates[0][1];
            if (x1 * y2 != x2 * y1) {
                return false;
            }
        }
        return true;
    }
}
```