### 解题思路
如果有子串可以组成，绝对不会第一次在拼接成的下一个字符串的位置找到自己。

### 代码

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        return (s + s).indexOf(s, 1) != s.length();
    }
}
```