执行用时: 0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗: 37.3 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路
位图法。

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        int[] count = new int[256];
        for(int i = 0; i < s1.length(); i ++) {
            count[s1.charAt(i) - ' '] ++;
            count[s2.charAt(i) - ' '] --;
        }
        for(int c: count) {
            if(c != 0) {
                return false;
            }
        }
        return true;
    }
}
```