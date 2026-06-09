执行用时 : **1389 ms**, 在所有 Java 提交中击败了 **5.01%** 的用户；
内存消耗 : 36.9 MB, 在所有 Java 提交中击败了 71.13% 的用户。
```
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) {
            return 0;
        }
        if (haystack.length() < needle.length()) {
            return -1;
        }
        int ans = 0;
        for (int j = 0, i = 0; j < haystack.length(); j++) {
            if (haystack.charAt(j) == needle.charAt(i)) {
                ans = j;
            }
            while (j < haystack.length() && i < needle.length() && haystack.charAt(j) == needle.charAt(i)) {
                i ++;
                j ++;
            }

            if (i >= needle.length()) {
                return ans;
            } else if (i > 0) {
                j = ans;
                i = 0;
            }
        }
        return -1;
    }
}
```
