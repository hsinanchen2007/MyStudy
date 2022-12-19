```
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)
            return "";

        int start = 0, end = 0, len = 1, realstart = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                start = i - 1;
                end = i;
                while (start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end)) {
                    start--;
                    end++;
                }
                if (len < end - start - 1) {
                    len = end - start - 1;
                    realstart = start + 1;
                }
            }
            if (i < s.length() - 1 && s.charAt(i - 1) == s.charAt(i + 1)){
                start = i - 1;
                end = i + 1;
                while (start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end)) {
                    start--;
                    end++;
                }
                if (len < end - start - 1) {
                    len = end - start - 1;
                    realstart = start + 1;
                }
            }
        }
        return s.substring(realstart, realstart + len);
    }
}
```
