### 解题思路
从左到右加数字就可以了。
- 可以先$trim()$一下左右空格
- 开头可能有$+$号
- 数字过大时可以在循环内判断直接返回


### 代码

```java
class Solution {
    public int myAtoi(String str) {
        if (str == null || str.trim().equals("")) return 0;
        str = str.trim();
        long ans = 0;
        int sig = str.charAt(0) == '-' ? -1 : 1;
        int n = str.length();
        for (int i = str.charAt(0) == '-' || str.charAt(0) == '+' ? 1 : 0; i < n; ++i) {
            char c = str.charAt(i);
            if (c >= '0' && c <= '9') {
                ans = ans * 10 + c - '0';
            }
            else break;
            if (ans * sig > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (ans * sig < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        ans = ans * sig;
        return (int)ans;
    }
}
```