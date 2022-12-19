思路是遍历字符串中的每个字符，匹配到空格后，修改为%20。
```
StringBuilder sb = new StringBuilder();
int length = s.length();
for(int i = 0; i < length; i++) {
    char c = s.charAt(i);
    if (c == ' ') {
        sb.append("%20");
    }else {
        sb.append(c);
    }
}
return sb.toString();
```