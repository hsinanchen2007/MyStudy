### 解题思路
打卡

### 代码

```java
class Solution {
    public int gcd(int x, int y){
        int r;
        while(y > 0){
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    public boolean canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false; 
        else if(x + y == z)  return true;
        else if(x == 0 || y == 0) return z == x || z == y;
        return z % gcd(x, y) == 0;
    }
}
```