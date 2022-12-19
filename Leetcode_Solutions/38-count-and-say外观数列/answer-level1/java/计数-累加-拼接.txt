### 解题思路

解题思路还是比较简单的，就是判断每个字符串跟之前一个是不是一样，一样就计数加一，否则把计数数量和字符拼接上去。其实可以使用递归让代码更加优雅，但是懒得写，直接使用了循环代替。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        for (int i = 1; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            int c = 1;
            char ss = s.charAt(0);
            for (int j = 1; j < s.length(); j++) {
                if (s.charAt(j) == ss) {
                    c += 1;
                } else {
                    sb.append(c);
                    sb.append(ss);
                    ss = s.charAt(j);
                    c = 1;
                }
            }
            sb.append(c);
            sb.append(ss);
            s = sb.toString();
        }
        return s;
    }
}
```