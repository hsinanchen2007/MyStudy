### 解题思路


### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int sl = 0;
        int sr = s.length() - 1;
        int tl = 0;
        int tr = t.length() - 1;
        int findCount = 0;
        while (sl <= sr && tl <= tr) {
            char slc = s.charAt(sl);
            char src = s.charAt(sr);
            char tlc = t.charAt(tl);
            char trc = t.charAt(tr);
            if (slc == tlc) {
                sl++;
                findCount++;
            }
            tl++;
            if (src == trc) {
                sr--;
                findCount++;
            }
            tr--;
        }
        return findCount == s.length();
    }
}
```