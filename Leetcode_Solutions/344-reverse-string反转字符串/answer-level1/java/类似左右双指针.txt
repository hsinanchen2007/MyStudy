```
class Solution {
    public void reverseString(char[] s) {
        int length = s.length;
        int n = length / 2;
        for (int i = 0; i < n; ++i) {
            char temp = s[i];
            s[i] = s[length - 1 - i];
            s[length - 1 - i] = temp;
        }
    }
}
```
