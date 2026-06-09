裴蜀定理（或贝祖定理）得名于法国数学家艾蒂安·裴蜀，说明了对任何整数a、b和它们的最大公约数d，关于未知数x和y的线性不定方程（称为裴蜀等式）：若a,b是整数,且gcd(a,b)=d，那么对于任意的整数x,y,ax+by都一定是d的倍数，特别地，一定存在整数x,y，使ax+by=d成立。

这道问题可转换为：
z = m * x + n * y
x=3 y=5 z=4
4 = 5-(3-(5-3)) 
y壶装5倒3得2, 2放在x壶，y壶装5，倒入x壶至满 
z是由x和y的各种线性组合得来
4 = (-2) * 3 + 2 * 5
根据裴蜀定理
z = gcd（x,y）
```
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
```
