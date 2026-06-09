### 解题思路


### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x > y){
            int temp = y;
            y = x; 
            x = temp;
        }
        if (x == z || y == z || (y - x) == z || z == 0) return true;
        if (x == y) return false;

        int j = 0;
        while(j != x){
            j -= x;
            if (j < 0) j += y;

            if (j == z || j + x == z) return true;
            if (j <= x && j + y == z) return true;
        }

        return false;
    }
}
```