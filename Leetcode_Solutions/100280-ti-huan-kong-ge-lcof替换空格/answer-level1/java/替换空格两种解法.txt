``` java
/**
 * 解法一
 */
class Solution {
    public String replaceSpace(String s) {
        if (s == null) {
            return s;
        }
        StringBuffer str = new StringBuffer(s.length());
        char[] ch = s.toCharArray();
        for (char c : ch) {
            if (c == ' ') {
                str.append("%20");
            } else {
                str.append(c);
            }
        }
        return str.toString();
    }
}

/**
 * 解法二
 */

class Solution {
    public String replaceSpace(String s) {
        if (s == null) {
            return s;
        }
        char[] chars = s.toCharArray();
        int n = 0;
        int index = 0;
        for (char ch : chars) {
            if (ch == ' ') {
                n++;
            }
        }
        char[] str = new char[s.length() + (n << 1)];
        for (int i = 0; i < s.length(); i++) {
            if (chars[i] == ' ') {
                str[index++] = '%';
                str[index++] = '2';
                str[index++] = '0';
            } else {
                str[index++] = chars[i];
            }
        }
        return new String(str);
    }
}
 
```
