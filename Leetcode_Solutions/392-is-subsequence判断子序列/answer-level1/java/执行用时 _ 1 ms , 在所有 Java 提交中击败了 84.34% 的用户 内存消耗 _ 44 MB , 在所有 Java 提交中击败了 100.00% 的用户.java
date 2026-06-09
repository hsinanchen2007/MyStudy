### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
            int from = 0;
        for (char c : s.toCharArray()) {
            int index = t.indexOf(c, from);
            if (index == -1) {
                return false;
            } else {
                from = index + 1;
            }
        }
        return true;
    }
}
```