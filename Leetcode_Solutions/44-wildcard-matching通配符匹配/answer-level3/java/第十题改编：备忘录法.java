```
class Solution {
    char[] scs;
    char[] pcs;
    Boolean[][] mono;  // 备忘录
    public boolean isMatch(String s, String p) {
        scs = s.toCharArray();
        pcs = p.toCharArray();
        mono = new Boolean[scs.length + 1][pcs.length + 1];
        return isMatch(0, 0);
    }

    public boolean isMatch(int i, int j) {
        if (mono[i][j] != null) return mono[i][j];
        Boolean r = false;
        if (j == pcs.length) {
            if (i == scs.length) {
                r = true;
            }
        } else {
            if (pcs[j] == '*') {
                while(j + 1 < pcs.length && pcs[j + 1] == '*') {
                    j++;
                }
                if(i == scs.length) {
                    r = isMatch(i, j + 1);
                } else {
                    r = isMatch(i + 1, j) || isMatch(i, j + 1);
                }
            } else {
                if (i == scs.length)
                    r = false;
                else
                    if (pcs[j] == '?' || scs[i] == pcs[j]) {
                        r = isMatch(i + 1, j + 1);
                    } else {
                        r = false;
                    }
            }
        }
        mono[i][j] = r;
        return r;
    }
}
```