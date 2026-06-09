```java
class Solution {
    public String shortestPalindrome(String s) {
        String r = new StringBuilder(s).reverse().toString();
        String str = s + "#" + r;
        int[] next = new int[str.length()];
        for (int i = 1; i < str.length(); i ++) {
            int j = next[i - 1];
            while (j > 0 && str.charAt(i) != str.charAt(j)) j = next[j - 1];
            j += str.charAt(i) == str.charAt(j) ? 1 : 0;
            next[i] = j;
        }
        return r.substring(0, r.length() - next[str.length() - 1]) + s;
    }
}
```