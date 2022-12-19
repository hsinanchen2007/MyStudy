### 解题思路
如果 d=gcd(a,b) d 是 a,b 的最大公约数，那么对于任意整数 x,y 一定有 ax+by 是 d 的倍数。
因此只需要找到 x,y 的最大公约数 d， 判断 z 是否是 d 的倍数

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        }
        if (x == 0 && y == 0) {
            return false;
        } else if (x == 0) {
            return y == z;
        } else if (y ==0) {
            return x == z;
        }
        if (x+y < z) {
            return false;
        }
        return z % gcd(x,y) == 0;
    }

    public int gcd(int m, int n) {
        if (m < n) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        if (m%n == 0) {
            return n;
        }
        return gcd(n, m%n);
    }
}
```