```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int startIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            int x = s.indexOf(s.charAt(i), startIndex);
            if (x < 0) {
                continue;
            }
            if (x < i) {
                max = Math.max(max, i - startIndex);
                startIndex = x + 1;
            }
        }
        max = Math.max(max, s.length() - startIndex);
        return max;
    }
}
```
