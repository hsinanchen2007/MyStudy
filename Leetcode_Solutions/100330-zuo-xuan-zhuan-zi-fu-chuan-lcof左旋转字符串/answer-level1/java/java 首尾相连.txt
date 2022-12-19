```
class Solution {
    public String reverseLeftWords(String s, int n) {
        int len = s.length();
        n %= len;
        s += s;
        return s.substring(n, n + len);
    }
}
```
