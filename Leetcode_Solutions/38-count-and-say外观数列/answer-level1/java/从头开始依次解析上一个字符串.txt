### 解题思路
从1开始依次向下解析上一个字符串。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        StringBuffer stringBuffer = new StringBuffer();
        String str = "1";
        while (n > 1) {
            char[] chars = str.toCharArray();
            int len = 0;
            char tag = chars[0];
            for (int i = 0; i < chars.length; i++) {
                if (tag == chars[i]) {
                    len++;
                } else {
                    stringBuffer.append(len);
                    stringBuffer.append(tag);
                    tag = chars[i];
                    len = 1;
                }
            }
            stringBuffer.append(len);
            stringBuffer.append(tag);
            str = stringBuffer.toString();
            stringBuffer.delete(0, stringBuffer.length());
            n--;
        }
        return str;
    }
}
```