### 解题思路
使用递归的方式处理斐波那契数列会是指数级别的复杂度，所以使用递推的方式 `ints[i] = ints[i-1].add(ints[i-2]);`，边界为`ints[0]=ints[1]=1`。

题目中的最大输入值为100，使用long类型一样会溢出，所以使用`BigInteger[]`来替代`long[]`。

![image.png](https://pic.leetcode-cn.com/22d08bf93224dfc417d0efad76a8d8208928977ed228978ae72dfe6405fb99a5-image.png)


### 代码

```java
import java.math.BigInteger;
class Solution {
    public int fib(int n) {
        BigInteger fib = getFib(n);
        return fib.mod(BigInteger.valueOf(1000000007L)).intValue();
    }

    private BigInteger getFib(int n) {
        if (n <= 1) {
            return BigInteger.valueOf(n);
        } else {
            BigInteger[] ints = new BigInteger[n];
            ints[0] = BigInteger.ONE;
            ints[1] = BigInteger.ONE;
            for (int i = 2; i < ints.length; i++) {
                ints[i] = ints[i-1].add(ints[i-2]);
            }
            return ints[n-1];
        }
    }
}
```