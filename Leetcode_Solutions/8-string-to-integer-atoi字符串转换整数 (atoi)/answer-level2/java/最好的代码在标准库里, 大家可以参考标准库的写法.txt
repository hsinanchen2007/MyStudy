Java 源码标准库分析: [parseInt()](https://www.jianshu.com/p/da80a793dd57)


```java
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        boolean negative = false;
        int max = -Integer.MAX_VALUE;
        int res = 0;
        if (str.length() == 0) {
            return 0;
        }
        int i = 0;
        if (str.charAt(i) == '+' || str.charAt(i) == '-') {
            if (str.charAt(i) == '-') {
                negative = true;
                max = Integer.MIN_VALUE;
            }
            i++;
        }

        while (i < str.length()){
            if (!(str.charAt(i) >= '0' && str.charAt(i) <= '9')) {
                break;
            }

            if (res < max / 10) {
                res = max;
                break;
            }

            int tmp = str.charAt(i) - '0';

            if (max + tmp > res * 10) {
                res = max;
                break;
            }

            res = res * 10 - tmp;
            i++;
        }

        return negative ? res : -res;
    }
}
```