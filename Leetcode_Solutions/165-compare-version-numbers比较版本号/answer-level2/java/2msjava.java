```
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int i = 0;
        int j = 0;
        while (i < v1.length && j < v2.length) {
            if (Integer.valueOf(v1[i]) > Integer.valueOf(v2[j]))
                return 1;
            else if (Integer.valueOf(v1[i]) < Integer.valueOf(v2[j]))
                return -1;
            i++;
            j++;
        }
        if (i < v1.length) {
            for (; i < v1.length; i++) {
                if (Integer.valueOf(v1[i]) != 0) {
                    return 1;
                }
            }
        }
        if (j < v2.length) {
            for (; j < v2.length; j++) {
                if (Integer.valueOf(v2[j]) != 0) {
                    return -1;
                }
            }
        }
        return 0;
    }
}
```
