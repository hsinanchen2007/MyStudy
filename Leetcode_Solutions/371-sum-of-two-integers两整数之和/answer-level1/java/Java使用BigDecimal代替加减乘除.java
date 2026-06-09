### 解题思路
Java使用BigDecimal代替加减乘除

### 代码

```java
import java.math.BigDecimal;
class Solution {
    public int getSum(int a, int b) {
        BigDecimal a1 = new BigDecimal(a);
        BigDecimal b1 = new BigDecimal(b);
        return a1.add(b1).intValue();
    }
}
```