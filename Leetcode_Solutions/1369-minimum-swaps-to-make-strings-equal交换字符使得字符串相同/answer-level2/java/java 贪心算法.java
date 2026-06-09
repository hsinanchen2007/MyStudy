```
class Solution {
    public int minimumSwap(String s1, String s2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int len = c1.length;
        int xy = 0;
        int yx = 0;
        for (int i = 0; i < len; i++) {
            if (c1[i] != c2[i]) {
                if (c1[i] == 'x') {
                    xy++;
                } else {
                    yx++;
                }
            }
        }
        if (((xy + yx) & 1) == 1) {
            return -1;
        } else {
            return (xy + 1) / 2 + (yx + 1) / 2;
        }
    }
}
```
