### 解题思路
首先，从两个水壶里的整体水量来看，每次操作，可分为下列情况：
1.往空壶里加满水，总量加x/y；
2.倒掉一壶水（满），总量减x/y；
3.倒掉一壶水（不满），总量变成x/y/0；
4.往不满的壶里加水，总量变为x/y/x+y；
5.从一个壶往另一个壶里倒水，总量不变；

所以，两个壶里水的总量一定是ax+by（a,b为整数），立即推，当z=ax+by时，返回true。

然后是贝祖定理：若存在整数a,b，使得ax+by=z成立，则z一定为x.y最大公因数的整数倍。

证明如下：

设x,y的最大公因数为d；
故存在整数i,j,使得x=id,y=jd；
若ax+by=z成立，则
ax+by = a*(id)+b(jd) = (ai+b*j)*d = z；
由此可得，z为d的整数倍。

所以，这道题就变成了判断z是否是x,y最大公因数的整数倍
### 代码

```java
class Solution {
    int gcd(int a,int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }

    boolean canMeasureWater(int x, int y, int z) {
        if (x == 0 && y == 0 ) return z == 0;
        if (z > x + y ) return false;
        int a = y == 0 ? gcd(y, x) : gcd(x, y);
        return z % a == 0;
    }
}
```