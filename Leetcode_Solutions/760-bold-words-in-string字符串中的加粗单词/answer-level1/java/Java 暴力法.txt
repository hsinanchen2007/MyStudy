```
class Solution {
    public String boldWords(String[] words, String S) {
        int len = S.length();
        int[] highLight = new int[len];
        for (String word : words) {
            int subLen = word.length();
            for (int i = 0; i <= len - subLen; i++) {
                if (word.equals(S.substring(i, i + subLen))) {
                    int start = i;
                    int end = i + subLen - 1;
                    while (start <= end) {
                        highLight[start] = 1;
                        start++;
                    }
                }
            }
        }
        String out = "";
        for (int j = 0; j < len; j++) {
            if (j == 0 && highLight[j] == 1) {
                out += "<b>";
                out += S.substring(j, j+1);
                if (highLight[j + 1] == 0) {
                    out += "</b>";
                }
            } else if (j + 1 < len && highLight[j] == 1 && highLight[j+1] == 0) {
                out += S.substring(j, j+1);
                out += "</b>";
            } else if (j + 1 < len && highLight[j] == 0 && highLight[j+1] == 1) {
                out += S.substring(j, j+1);
                out += "<b>";
            } else if (j + 1 == len && highLight[j] == 1) {
                out += S.substring(j, j+1);
                out += "</b>";
            } else {
                out += S.substring(j, j+1);
            }
        }
        return out;
    }
}
```
