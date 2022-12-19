```java
class Solution {
    public int compareVersion(String v1, String v2) {
        int i = 0;
        int j = 0;
        while (i < v1.length() && j < v2.length()) {
            int nexti = v1.indexOf(".", i);
            if (nexti == -1) {
                nexti = v1.length();
            }
            int nextj = v2.indexOf(".", j);
            if (nextj == -1) {
                nextj = v2.length();
            }
            int cmp = compareDigit(v1.substring(i, nexti), v2.substring(j, nextj));
            if (cmp == 0) {
                i = nexti + 1;
                j = nextj + 1;
                continue;
            }
            return cmp;
        }
        while (i < v1.length()) {
            int nexti = v1.indexOf(".", i);
            if (nexti == -1) {
                nexti = v1.length();
            }
            int cmp = compareDigit(v1.substring(i, nexti), "0");
            if (cmp == 0) {
                i = nexti + 1;
                continue;
            }
            return cmp;
        }

        while (j < v2.length()) {
            int nextj = v2.indexOf(".", j);
            if (nextj == -1) {
                nextj = v2.length();
            }
            int cmp = compareDigit("0", v2.substring(j, nextj));
            if (cmp == 0) {
                j = nextj + 1;
                continue;
            }
            return cmp;
        }
        return 0;
    }

    private int compareDigit(String s1, String s2) {
        if (s1.length() == 0 && s2.length() == 0) {
            return 0;
        }
        if (s1.length() == 0) {
            return Integer.parseInt(s2) == 0 ? 0 : -1;
        }
        if (s2.length() == 0) {
            return Integer.parseInt(s1) == 0 ? 0 : 1;
        }
        int diff = Integer.parseInt(s1) - Integer.parseInt(s2);
        return Integer.compare(diff, 0); 
    }
}
```
