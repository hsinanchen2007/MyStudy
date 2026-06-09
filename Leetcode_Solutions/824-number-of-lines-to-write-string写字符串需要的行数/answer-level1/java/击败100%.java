```java
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int cnt = 100;
        int line = 1;
        for (char c : S.toCharArray()) {
            int w = widths[c - 'a'];
            if (w <= cnt) {
                cnt -= w;
            } else {
                cnt = 100 - w;
                line++;
            }
        }
        return new int[] {line, 100 - cnt};
    }
}
```