### 解题思路
### 关键是判断溢出：
### 一、上溢
    考虑两种情况：
        1）result > Integer.MAX_VALUE / 10，此时肯定溢出。
        2）result == Integer.MAX_VALUE / 10 && ch - '0' > 7，后面的7是因为Integer.MAX_VALUE为2147483647，
        末位为7。
### 二、下溢
    考虑两种情况：
        1）-result < Integer.MIN_VALUE / 10，此时肯定溢出。
        2）-result == Integer.MIN_VALUE / 10 && ch - '0' > 8，后面的8是因为Integer.MIN_VALUE为-2147483648，
        末位为8.

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int result = 0;
        boolean begin = false;
        boolean sign = false;//true -, false +
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (begin) {
                if (ch - '0' >= 0 && ch - '0' <= 9) {
                    //为正数 sign = false
                    if (!sign && (result == Integer.MAX_VALUE / 10 && ch - '0' > 7 || result > Integer.MAX_VALUE / 10)) {
                        //2147483647
                        return Integer.MAX_VALUE;
                    }
                    //为负数 sign = true
                    if (sign && (-result == Integer.MIN_VALUE / 10 && ch - '0' > 8 || -result < Integer.MIN_VALUE / 10)) {
                        //-2147483648
                        return Integer.MIN_VALUE;
                    }
                    result = result * 10 + (ch - '0');
                    continue;
                }

                return sign ? -result : result;
            } else {
                if (ch == ' ') {
                    continue;
                }
                if (ch == '+') {
                    begin = true;
                    continue;
                }
                if (ch == '-') {
                    begin = true;
                    sign = true;
                    continue;
                }
                if (ch - '0' >= 0 && ch - '0' <= 9) {
                    result = ch - '0';
                    begin = true;
                    continue;
                }

                return 0;
            }
        }

        return sign ? -result : result;
    }
}
```