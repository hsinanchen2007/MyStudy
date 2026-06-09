### 解题思路
用了新学的bm算法，用时7ms，击败了19.07%的java用户，哭哭==
判断字符串是否为空那里或许可以优化下
### 代码

```java

class Solution {
    private void suffix(String pattern, int m, int[] suffix) {
        int i, j;
        suffix[m - 1] = m;
        char[] p = pattern.toCharArray();
        for (i = m - 2; i >= 0; i--) {
            j = i;
            while (j >= 0 && p[j] == p[m - 1 - i + j]) j--;
            suffix[i] = i - j;
        }

    }

    private void preBmBc(String pattern, int[] bmBc) {
        int m = pattern.length();
        int i;
        char[] p = pattern.toCharArray();
        for (i = 0; i < 256; i++) {
            bmBc[i] = m;
        }
        for (i = 0; i < pattern.length() - 1; i++) {
            bmBc[p[i]] = m - 1 - i;
        }

    }

    private void preBmGs(String pattern, int[] bmGs) {
        int i = 0;
        int m = pattern.length();
        int[] suff = new int[m];
        suffix(pattern, m, suff);

        //case3
        for (i = 0; i < m; i++) {
            bmGs[i] = m;
        }

        // Case2
        int j = 0;
        for (i = m - 1; i >= 0; i--) {
            if (suff[i] == i + 1) {
                for (; j < m - 1 - i; j++) {
                    if (bmGs[j] == m)
                        bmGs[j] = m - 1 - i;
                }
            }
        }

        //case1
        for (i = 0; i < m - 1; i++) {
            bmGs[m - 1 - suff[i]] = m - 1 - i;
        }

    }

    public int strStr(String text, String pattern) {
        if (text ==null || text.isEmpty()) {
            if (pattern==null||pattern.isEmpty()) {
                return  0;
            }
            else{
                return -1;
            }
        }else if(pattern==null||pattern.isEmpty())
            return 0;
        int p_len = pattern.length();
        int t_len = text.length();
        int[] bmGs = new int[p_len];
        int[] bmBc = new int[256];
        char[] p = pattern.toCharArray();
        char[] t = text.toCharArray();
        preBmBc(pattern, bmBc);
        preBmGs(pattern, bmGs);
        int j = 0;
        int i = 0;
        while (j <= t_len - p_len) {
            for (i = p_len - 1; i >= 0 && p[i] == t[i + j]; i--) ;
            if (i < 0) {
                return j;
            } else {
                j += Math.max(bmGs[i], bmBc[t[i + j]] - (p_len - 1 - i));

            }
            //j+=max(shift(gs),shift(bc);

        }
        return -1;
    }



}


```