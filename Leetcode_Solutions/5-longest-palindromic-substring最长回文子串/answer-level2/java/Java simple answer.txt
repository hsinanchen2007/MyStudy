### 代码

```java
class Solution {
    int start;
    int end;
    int maxLength;
    public String longestPalindrome(String s) {
        if (s.length() < 2) return s;
        for (int i = 0; i < s.length() - 1; i++) {
           check(i, i, s);
           check(i, i + 1, s);
        }
        return s.substring(start, end);
    }
    private void check(int i, int j, String s) {
        while(i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxLength = j - i - 1;
            start = i + 1;
            end = j;
        }
    }
}
```