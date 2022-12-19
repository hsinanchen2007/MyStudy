### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        boolean[] booleans = new boolean[128];
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (booleans[c]) {
                ans = ans + 2;
                booleans[c] = false;
            } else {
                booleans[c] = true;
            }
        }
        return ans < s.length() ? ans + 1 : ans;
    }
}
```