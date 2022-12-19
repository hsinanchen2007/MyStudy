### 解题思路
这题真是想破脑袋（要哭了

结论一句话就是`z`如果能被`x`和`y`的**最大公约数**整除就可以

（当然`z`不能比`x`与`y`之和还要大；`x`与`y`至少一个为0时，`z`也必须为0或者为那个桶的容量）

至于如何证明。。请移步大神们的。。

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z > x+y) {
            return false;
        }
        if(x == 0 || y == 0) {
            return z == Math.max(x, y) || z == 0;
        }
        return z % getGCD(x, y) == 0;
    }

    public int getGCD(int a, int b) {
        return a % b == 0 ? b : getGCD(b, a % b);
    }
}
```