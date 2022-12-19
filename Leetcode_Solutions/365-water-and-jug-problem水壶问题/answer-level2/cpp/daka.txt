参考别人的思路。。

[https://blog.csdn.net/qq_40636117/article/details/80340421]()

```
class Solution {
public:
    int gcd(int x, int y)
    {
        return y == 0? x: gcd(y, x % y);
    }

    bool canMeasureWater(int x, int y, int z)
    {
        if(z == 0)
            return true;
        if(x + y >= z && z % gcd(x, y) == 0)
            return true;
        return false;
    }
};
```
