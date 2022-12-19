```
class Solution {
    public String sortString(String s) {
        int n = s.length();
        if (n == 0) {
            return s;
        }
        int[] map = new int[26];
        char[] res = new char[n];
        for (int i = 0; i < n; ++i) {
            ++map[s.charAt(i) - 'a'];
        }
        int x = 0, i;
        while (x < n) {
            for (i = 0; i < 26; ++i) {
                if (map[i] > 0) {
                    res[x++] = (char)('a' + i);
                    --map[i];
                }
            }
            for (i = 25; i >= 0; --i) {
                if (map[i] > 0) {
                    res[x++] = (char)('a' + i);
                    --map[i];
                }
            }
        }
        return new String(res);
    }
}
```
