逐个字符读取到StringBuffer，过滤不需要字符，并进行大小写转换。
最后使用StringBuffer的reverse()方法翻转字符串，判断是否相等即可。

```
class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9'))) sb.append(c);
            if ((c >= 'A') && (c <= 'Z')) sb.append((char)(c+32));
        };
        return sb.toString().equals(sb.reverse().toString());
    }
}
```
