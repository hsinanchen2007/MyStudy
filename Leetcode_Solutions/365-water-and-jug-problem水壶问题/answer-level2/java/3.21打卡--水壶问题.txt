### 解题思路
很有趣的一道题，多看看大家的解法

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x == 0 || y == 0) {
            if (x == z || y == z) return true;
            return false;
        }
        if (x + y < z) return false;
        int tmp = gcd(x, y);
        return z % tmp == 0;
    }
    private int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
}
```