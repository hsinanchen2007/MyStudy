### 解题思路


### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) {
            return true;
        }
        char[] s1 = s.toCharArray();
        char[] t1 = t.toCharArray();
        int index = 0;
        for (int i = 0; i < t1.length; i++) {
            if (s1[index] == t1[i]) {
                index++;
            }
            if (index == s1.length) {
                return true;
            }
        }
        return false;
    }
}
```