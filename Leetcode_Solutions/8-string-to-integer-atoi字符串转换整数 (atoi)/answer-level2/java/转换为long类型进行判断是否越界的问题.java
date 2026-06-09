### 解题思路
转换为long类型进行判断是否越界的问题

### 代码
```java
class Solution {
    public int myAtoi(String str) {
        // "  21213    "
        str = str.trim();
        
        // "4193 with words" 
        if (str.indexOf(' ') > 0) {
            str = str.substring(0, str.indexOf(' '));
        } 
        
        // ""
        if (str.length() == 0) {
            return 0;
        }
        char[] chars = str.toCharArray();
        int len = chars.length;
        int index = 0;
        boolean negative = false;
        if (chars[index] == '-') {
            negative = true;
            index++;
        // "+1"
        } else if (chars[index] == '+') {
            index++;
        } else if (chars[index] < '0' || chars[index] > '9') {
            return 0;
        }

        long ans = 0;
        for (; index < len; index++) {
            char temp = chars[index];
            // 3.14165926
            if (temp < '0' || temp > '9') {
                break;
            }
            int digit = temp - '0';
            ans = ans * 10 + digit;
            if (ans > Integer.MAX_VALUE) {
                if (negative) {
                    return Integer.MIN_VALUE;
                } else {
                    return Integer.MAX_VALUE;
                }
            }
        }
        if (negative) {
            return - ((int) ans);
        } else {
            return (int) ans;
        }
    }
}
```

