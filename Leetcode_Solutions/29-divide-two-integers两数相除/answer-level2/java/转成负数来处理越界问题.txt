### 解题思路
此处撰写解题思路
看了别人代码相加 被除数远小于除数时增加倍数。最后把所有正数改成，负数的形式处理。这样可以免于正数越界问题，java源码也是使用负数来处理加减问题，可以参考，Interger的String改成int方法
### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend < 0 && dividend == Integer.MIN_VALUE) {
                return Integer.MAX_VALUE;
            }
            return -dividend;
        }
        boolean negative = false;
        if ((dividend ^ divisor) < 0) {
            negative = true;
        }
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }

        int res = 0;
        int count = 1;
        int temp = divisor;
        while (dividend <= divisor) {
            dividend = dividend - temp;
            res += count;
            if (dividend <= (temp << 1)) {
                temp += temp;
                count += count;
            } else {
                temp = divisor;
                count = 1;
            }

        }
        return negative ? -res : res;
    }
}
```