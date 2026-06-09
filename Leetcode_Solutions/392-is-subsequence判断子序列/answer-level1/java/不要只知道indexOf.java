### 解题思路
indexOf还有一个多参数的，第二个参数表示起始位置，可以过滤到重复的情况，了解API 重要。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = -1;
        for (char c : s.toCharArray()) {
            i = t.indexOf(c, i + 1);
            if (i == -1) {
                return false;
            }
        }
        return true;
    }
}
```