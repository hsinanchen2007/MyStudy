### 解题思路
规律很简单，发现很困难。还是背下来吧

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0); //找到x,y的最大公约数能否z被整除
    }
    private int gcd(int x, int y) {      //辗转相除法
        return y == 0 ? x : gcd(y, x % y);
    
    }
}
```