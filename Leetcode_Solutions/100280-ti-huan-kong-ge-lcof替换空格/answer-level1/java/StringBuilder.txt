### 解题思路
如果要对一个字符串进行大量的修改，推荐使用StringBuilder进行构造

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') sb.append("%20");
            else sb.append(s.charAt(i));
        } 
        return sb.toString();
    }
}
```