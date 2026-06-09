### 解题思路
java 中的BigInteger api中的add方法

### 代码

```java
import java.math.BigInteger;

class Solution {
    public int getSum(int a, int b) {
        BigInteger i = new BigInteger(Integer.toString(a));
        BigInteger j = new BigInteger(Integer.toString(b));
        return i.add(j).intValue();
    }
}
```