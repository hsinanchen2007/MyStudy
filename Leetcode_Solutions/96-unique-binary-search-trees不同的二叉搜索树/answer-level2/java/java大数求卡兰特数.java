### 解题思路
此处撰写解题思路

### 代码

```java
import java.math.BigInteger;
class Solution {
    public int numTrees(int n) {
       BigInteger res = new BigInteger("1");
        for (int i = 0; i < n; i++) res = res.multiply(new BigInteger(String.valueOf(2 * n - i))).divide(new BigInteger(String.valueOf(i+1)));
        return res.divide(new BigInteger(String.valueOf(n + 1))).intValue();
    }
}
```