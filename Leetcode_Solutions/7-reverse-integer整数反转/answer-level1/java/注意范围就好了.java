### 解题思路
注意int类型的范围

### 代码

```java
class Solution {
    public int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int last = x % 10;

            x = x / 10;
            if (result < Integer.MIN_VALUE / 10 || result > Integer.MAX_VALUE / 10) {
                return 0;
            }
            result = result * 10 + last;
        }
        return result;
    }
}
```