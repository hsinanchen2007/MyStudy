### 解题思路
如果结果是true，那么z一定可以表示为ax+by的形式，其中a, b为整数。
如果ax+by=z有整数解a, b，设x, y的最大公因数为d。根据辗转相除法我们知道，mx+ny=d，其中m, n也是整数。
令x'=x/d, y'=y/d，则 ax+by = ax'd + by'd = (ax'+by')d = z。所以，z是d的整数倍。并且，如果z是d的整数倍的同时x+y>=z，则结果一定是true，这是因为假如z=kd，那么只要将mx+ny=d两边同时乘k就能得到(km)x+(kn)y=z，再加上z的大小限制z<=x+y，所以可以通过有限次倒水得到z。
再考虑一些边界条件这道题就解出了。

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (x == 0) return z == y;
        if (y == 0) return z == x; 
        if (x + y < z) return false;
        return z % gcd(x, y) == 0;
    }
};
```