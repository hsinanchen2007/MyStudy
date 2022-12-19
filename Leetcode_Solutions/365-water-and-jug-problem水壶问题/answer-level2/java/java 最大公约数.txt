### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        } else if (x + y < z) {
            return false;
        } else if (y == 0) {
            return x == z;
        } else {
            while (x % y != 0) {
                int temp=x%y;
                x=y;
                y=temp;
            }
            return z%y==0;
        }
    }
}
```