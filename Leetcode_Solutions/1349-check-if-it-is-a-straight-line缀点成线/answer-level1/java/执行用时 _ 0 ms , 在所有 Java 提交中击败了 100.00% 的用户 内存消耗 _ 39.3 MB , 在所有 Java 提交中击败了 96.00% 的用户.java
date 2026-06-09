### 解题思路
基础题，斜率必须全部相等才会返回true。

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        double K = (double)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        for(int i = 0;i<coordinates.length-1;i++) {
            if((double)(coordinates[i+1][1]-coordinates[i][1])/(coordinates[i+1][0]-coordinates[i][0])!=K) {
                return false;
            }
        }
        return true;
    }
}
```