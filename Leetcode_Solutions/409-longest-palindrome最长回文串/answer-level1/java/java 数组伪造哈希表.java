```
class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[58]; // z - A = 57
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'A']++;
        }
        int num = 0;
        for (int c: count) {
            num += c / 2 * 2;
        }
        if (num < s.length())
            num++;
        return num;
    }
}
```
