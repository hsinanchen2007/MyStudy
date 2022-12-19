### 解题思路
此处撰写解题思路
执行用时 :
31 ms
, 在所有 Java 提交中击败了
49.62%
的用户

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if (s.length() == 0) {
            return ' ';
        }
        for (char c : s.toCharArray()) {
            if (s.indexOf(c) == s.lastIndexOf(c)) {
                return c;
            }
        }

        return ' ';
    }
}
```