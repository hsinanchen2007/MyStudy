### 解题思路
分两种情况：
1. X >= Y时，只能使用减法使得X = Y，共需要X - Y次操作；
2. X < Y时，可以轻易看出无论X > (Y + 1) / 2还是X < (Y +1) / 2，先达成X = (Y + 1) / 2为最优办法。

![image.png](https://pic.leetcode-cn.com/0c4ff437ab8b8c465f46a0a4004ad807919b09a4db21c4d7f71bbb2f5fafc0cb-image.png)

### 代码

```java
class Solution {
    public int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        return brokenCalc(X, (Y + 1) >>> 1) + 1 + ((Y & 1) == 1 ? 1 : 0);
    }
}
```