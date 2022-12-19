使用Java给我门提供的BigInteger类来计算，简单直观。

```java
import java.math.BigInteger;
class Solution {
    public int[] plusOne(int[] digits) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < digits.length; i++) {
            sb.append(digits[i]);
        }

        BigInteger bi = new BigInteger(sb.toString());
        bi = bi.add(new BigInteger("1"));
        String s = bi.toString();
        int r[] = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            r[i] =Integer.parseInt(s.substring(i, i + 1));
        }
        return r;
    }
}
```