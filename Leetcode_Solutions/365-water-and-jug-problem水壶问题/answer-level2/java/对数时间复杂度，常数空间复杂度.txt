### 解题思路
贝祖定理

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x + y) {
            return false;
        } else if(z == 0 || z == x || z == y) {
            return true;
        }
        while(y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return z % x == 0;
    }
}
```