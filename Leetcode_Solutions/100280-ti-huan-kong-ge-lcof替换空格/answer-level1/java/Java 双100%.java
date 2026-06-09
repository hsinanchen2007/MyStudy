### 解题思路
使用Stringbuilder处理动态字符串，可以提高速度。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        char[] str = s.toCharArray();
        StringBuilder ans = new StringBuilder();
        for (char c:str) {
            if (c == ' ')
                ans.append("%20");
            else
                ans.append(c);
        }
        return ans.toString();
    }
}
```