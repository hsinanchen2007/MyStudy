### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        Arrays.sort(sarr);
        Arrays.sort(tarr);
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (sarr[i] != tarr[i]) {
                return false;
            }
        }
        return true;


    }
}
```