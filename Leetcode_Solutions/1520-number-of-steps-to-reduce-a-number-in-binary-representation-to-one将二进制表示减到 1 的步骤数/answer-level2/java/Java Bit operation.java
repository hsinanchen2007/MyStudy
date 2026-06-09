```java
import java.math.BigInteger;

class Solution {
    public int numSteps(String s) {
        int index = s.length() - 1;
        int count = 0;
        char[] chars = s.toCharArray();
        while (index > 0) {
            if (chars[index] == '0') {
                count++;
                index--;
            } else {
                // 1101
                //110111
                count++;
                while (index >= 0 && chars[index] == '1') {
                    count++;
                    index--;
                }
                if (index > 0) {
                    chars[index] = '1';
                }
            }
        }
        return count;
    }
}
```