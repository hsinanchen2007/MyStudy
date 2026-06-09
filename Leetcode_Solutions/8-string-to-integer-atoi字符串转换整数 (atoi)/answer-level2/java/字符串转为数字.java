### 解题思路
此处撰写解题思路
处理空格可以使用trim()，不过有时候容易忘记，于是干脆就自己写，直接将字符串转为字符数组方便操作，
首个符号只有为+或者-才有效，别的符号直接返回0，使用循环进行转换时要保证为数字，不是数字时则直接跳出，包括小数点，进行数字转化时一定要先判断ans > (Integer.MAX_VALUE - digit) / 10，不然容易先超出范围
### 代码

```java
class Solution {
    public int myAtoi(String str) {
        char[] chars = str.toCharArray();
        int n = chars.length;
        int index = 0;
        while (idx < n && chars[index] == ' ') {
            index++;
        }
        if (index == n) {
            return 0;
        }
        boolean negative = false;
        if (chars[index] == '-') {
            negative = true;
            index++;
        } else if (chars[index] == '+') {
            index++;
        } else if (!Character.isDigit(chars[index])) {
            return 0;
        }
        int ans = 0;
        while (index < n && Character.isDigit(chars[index])) {
            int digit = chars[index] - '0';
            if (ans > (Integer.MAX_VALUE - digit) / 10) {
                // 本来应该是 ans * 10 + digit > Integer.MAX_VALUE
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            ans = ans * 10 + digit;
            index++;
        }
        return negative? -ans : ans;
    }
}
```