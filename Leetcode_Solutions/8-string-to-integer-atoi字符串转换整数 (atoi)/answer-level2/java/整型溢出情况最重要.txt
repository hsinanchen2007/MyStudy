### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public int myAtoi(String str) {
        if (str == null) {
            return 0;
        }
        str = str.trim();
        if ("".equals(str)) {
            return 0;
        }
        int res = 0;
        int i = 0;
        boolean neg = false;
        if (str.charAt(i) == '+' || str.charAt(i) == '-') {
            neg = (str.charAt(i) == '-');
            i++;
        }
        while (i < str.length() && isDigit(str.charAt(i))) {
            int n = str.charAt(i++) - '0';
            if (outOfBound(res, n)) {
                return neg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            res = res * 10 + n * (neg ? -1 : 1);
        }
        return res;
    }

    //关键函数
    private boolean outOfBound(int n, int m) {
        if (n <= Integer.MIN_VALUE / 10) {
            return m > 8 || n < Integer.MIN_VALUE / 10; // 8 == (-Integer.MIN_VALUE % 10)
        }
        if (n >= Integer.MAX_VALUE / 10) {
            return m > 7 || n > Integer.MAX_VALUE / 10; // 7 == (Integer.MAX_VALUE % 10)
        }
        return false;
    }

    private boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
}
```