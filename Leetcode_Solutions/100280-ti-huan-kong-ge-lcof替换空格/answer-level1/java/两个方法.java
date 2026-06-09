照旧写个题解记录心路历程。
这道题太有成就感了，因为用Java是真的方便，耿直的思路：遇到空格就变成"%20"，十分简单，于是有了下面的代码：
```java
class Solution {
    public String replaceSpace(String s) {
        if (s.length() == 0) return s;
        StringBuilder sb = new StringBuilder();
        char ch = ' ';
        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (ch == ' ') {
                sb.append("%20");
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
```
可是后面转念一想，要是我用的不是Java，是c或者cpp，那没有append了，所以就试着换种思路。
其实也很简单，也是遇到空格就换成%20，只不过强制让自己用char数组来实现了一次。
用了char数组的话，就需要考虑new多长的数组了，所以需要先找到空格数量，然后new一个合适长度的char数组。
```java
class Solution {
    public String replaceSpace(String s) {
        if (s.length() == 0) return s;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') cnt++;
        }
        if (cnt == 0) return s;
        char ch = ' ';
        char[] tmp = new char[s.length() + cnt * 2];
        for (int i = s.length() - 1, j = tmp.length - 1; i >= 0; i--) {
            ch = s.charAt(i);
            if (ch == ' ') {
                tmp[j--] = '0';
                tmp[j--] = '2';
                tmp[j--] = '%';
            } else {
                tmp[j--] = ch;
            }
        }
        return String.valueOf(tmp);
    }
}
```
