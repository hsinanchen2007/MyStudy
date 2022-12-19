```Java []
    public void reverseString(char[] s) {
        int end = s.length;
        int half = end / 2;
        end = end - 1;
        for (int i = 0; i < half && end >= 0; ++i, --end) {
            s[i] ^= s[end];
            s[end] ^= s[i];
            s[i] ^= s[end];
        }
    }
```
