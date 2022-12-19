```
class Solution {
    public void reverseWords(char[] s) {
        int l = 0, r = s.length - 1;

        r(s, l, r);
        l = 0;
        r = 0;
        while(r <= s.length) {
            while(r < s.length && s[r] != ' ') 
                r ++;
            r(s, l, r - 1); 
            l = r + 1;
            r = l;
        }
    }

    private void r(char[] s, int l, int r) {
        while(l < r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l ++;
            r --;
        }
    }
}
```
