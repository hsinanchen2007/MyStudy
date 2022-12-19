### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() <= 0) return s;
        int l = 0;
        int r = 0;
        StringBuilder sb = new StringBuilder(s);
        int len = sb.length();
        while (r < len) {
            if (r == len - 1) {
                reverse(sb, l, r);
                return sb.toString();
            }
            if (sb.charAt(r) == ' ') {
                reverse(sb, l, r - 1);
                r++;
                l = r;
            }
            r++;
        }
        return sb.toString();
    }

    private void reverse(StringBuilder sb, int fromIndex, int toIndex) {
        if (fromIndex >= toIndex || toIndex < 0) return;
        while (fromIndex < toIndex) {
            char tmp = sb.charAt(fromIndex);
            sb.setCharAt(fromIndex, sb.charAt(toIndex));
            sb.setCharAt(toIndex, tmp);
            fromIndex++;
            toIndex--;
        }
    }
}
```

* 因为string 不允许修改这里使用了stringbuilder其实不算原字符串上操作