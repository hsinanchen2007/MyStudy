### 解题思路
找出关键等式，发现规律，总结结论。

### 代码

```java
class Solution {
    // 由题意分析可得：只要找到m * x + n * y = z 有整数解m，n即可。
    // 当且仅当 z 是 x,y 的最大公约数的倍数时等式成立，因此我们只需要找到 x,y 的最大公约数并判断 z 是否是它的倍数即可。
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return (z == 0) || (x + y == z);
        }

        return z % gcd(x, y) == 0; // 检查z是否为x，y的最大公约数的倍数
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```