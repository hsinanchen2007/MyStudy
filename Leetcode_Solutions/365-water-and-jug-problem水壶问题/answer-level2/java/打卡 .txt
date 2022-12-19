### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :36.7 MB, 在所有 Java 提交中击败了13.93%的用户

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return z == 0 || x + y == z;
        }

        int l = x % y;
        while (l != 0) {
            x = y;
            y = l;
            l = x % y;
        }

        return z % y == 0;
    }
}
```