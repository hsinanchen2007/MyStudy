思路：两个子串直接相加。
```
class Solution {
    public String reverseLeftWords(String s, int n) {
        if (n >= s.length()) return s;
        return s.substring(n, s.length()) + s.substring(0,n);
    }
}
```
