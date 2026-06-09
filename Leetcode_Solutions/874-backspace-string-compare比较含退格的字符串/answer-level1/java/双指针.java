```
// beat 99.58%(中文) 100%(英文)
    public boolean backspaceCompare(String S, String T) {
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();

        int i = s.length-1, j = t.length-1;
        int cs = 0, ct = 0; // 从右至左扫描记录'#'的位置
        while (i >= 0 && j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') ++cs;
                else if (cs > 0) --cs;
                else break;
                --i;
            }

            while (j >= 0) {
                if (t[j] == '#') ++ct;
                else if (ct > 0) --ct;
                else break;
                --j;
            }

            // i,j位置上若是字母
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if (i >= 0 && j < 0 || i < 0 && j >= 0) return false;
            --i;
            --j;
        }
        while (i >= 0) {
            if (s[i] == '#') ++cs;
            else if (cs > 0) --cs;
            else return false;
            --i;
        }
        while ( j >= 0) {
            if (t[j] == '#') ++ct;
            else if (ct > 0) --ct;
            else return false;
            --j;
        }
        return true;
    }
```
