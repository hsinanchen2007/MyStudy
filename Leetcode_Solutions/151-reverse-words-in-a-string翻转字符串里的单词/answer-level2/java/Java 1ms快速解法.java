### 解题思路
![1586484695(1).jpg](https://pic.leetcode-cn.com/06830f470fb1adceebcfbe36ebef3cb121bb962f8d40413f141f39e42afbf22e-1586484695\(1\).jpg)

通过split函数切块，再用StringBuilder拼接

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] strings = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = strings.length-1;i >= 0;i--) {
            String str = strings[i];
            if (null != str && !str.equals("")) {
                sb.append(str).append(" ");
            }
        }
        if (sb.length() > 0)
            return sb.substring(0,sb.length()-1);
        return "";
    }
}
```