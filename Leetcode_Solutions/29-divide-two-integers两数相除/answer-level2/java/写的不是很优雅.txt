用移位找倍数，由于负数比正数边界要大1，导致代码不能很优雅

```java
class Solution {

    public int divide(int dividend, int divisor) {
        boolean minInt = dividend == Integer.MIN_VALUE; // 被除数是否是Integer的最小值
        if (dividend == 0 || !minInt && divisor == Integer.MIN_VALUE) {
            return 0;
        }
        if (minInt && divisor == Integer.MIN_VALUE) { // 到这里完全排除了除数是Integer最小值的情况
            return 1;
        }

        boolean flag = (dividend ^ divisor) >= 0; // 判断同号还是异号
        dividend = minInt ? Integer.MAX_VALUE : dividend > 0 ? dividend : -dividend; // 被除数变成正数
        divisor = divisor > 0 ? divisor : -divisor; // 除数变成正数

        int n = 0;
        if (divisor < Integer.MAX_VALUE >> 5) { // 除数小于Integer.MAX_VALUE / (2^5)的情况
            int c = 0;
            while (dividend >= divisor) {
                int val = divisor << c; // divisor * (2 ^ c)
                if (dividend >= val && val < (Integer.MAX_VALUE >> 1)) { // 加判断，防止越界
                    c++;
                    continue;
                }
                dividend -= (val >> 1); // 减掉 divisor * (2^(c-1))
                n += 1 << (c - 1); // 倍数加进去

                c = 0; // 倍数置零
            }
        } else { // 除数大于Integer.MAX_VALUE / (2^5)时，最多也只需要32次循环就能结束了
            while (dividend >= divisor) {
                n++;
                dividend -= divisor;
            }
        }


        n = flag ? n : -n; // 正负号校正回来

        if (minInt && divisor - dividend == 1) { // 当被除数是Integer的最小值时，要判断一下是否余数只差1，若是得补足倍数
            if (!flag) {
                n -= 1;
            } else if (n < Integer.MAX_VALUE) {
                n += 1;
            }
        }

        return n;
    }

}
```