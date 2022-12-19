### 解题思路
从x, y倒过来，倒过去，实际在反复取余数，本质是公约数。
1、判断极端场景，加以剔除；
2、计算x, y的最大公约数，如果能整除z，则为true。

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0 && x == 0 && y == 0) {
            return true;
        }
        if (z < 0 || (x == 0 && y == 0)) {
            return false;
        }
        if (z == 0 || z == x + y) {
            return true;
        }
        if (x == 0 && y != z || y == 0 && x != z) {
            return false;
        }
        if (z > x + y) {
            return false;
        }

        // 求最大公约数
        int bigComponent;
        int tmpMax = Math.max(x, y);
        int tmpMin = Math.min(x, y);
        bigComponent = tmpMax % tmpMin;
        if (bigComponent == 0) {
            if (z % tmpMin == 0) {
                return true;
            }
        }
        while (bigComponent != 0) {
            tmpMax = tmpMin;
            tmpMin = bigComponent;
            bigComponent = tmpMax % tmpMin;
        }
        if (z % tmpMin == 0) {
            return true;
        }
        return false;
    }
}
```