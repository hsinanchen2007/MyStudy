参照[Clean c++ code](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/clean-c-code-by-frank588/)加入自己的理解写了一个Java版，不得不说，原作者思路真的很巧妙！
```java
class Solution {
    public int myAtoi(String str) {
        if (str == null) {
            return 0;
        }
        // 偷懒做法，去掉空格，也可以用while循环来做
        String temp = str.trim();
        if (temp == "" || temp.length() == 0) {
            return 0;
        }
        boolean flag = true;
        char[] bits = temp.toCharArray();
        int i = 0;
        int res = 0;
        int bit = 0;
        if (bits[0] == '-') {
            flag = false;
        } 
        if (bits[0] == '+' || bits[0] == '-') {
            i++;
        }
        for (; i < bits.length; i++) {
            if (bits[i] >= '0' && bits[i] <= '9') {
                bit = bits[i] - '0';
            } else {
                break;
            }
            // 这里巧妙的应用了如果溢出就取最大值 Integer.MAX_VALUE 或 Integer.MIN_VALUE
            if (res > Integer.MAX_VALUE/10 || (res == Integer.MAX_VALUE/10 && bit > 7)) {
                return flag ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            res = res * 10 + bit;
        }
        return flag ? res : -res;
    }
}
```
