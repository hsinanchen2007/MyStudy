```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int p = 0;
        while (p<v1.length || p<v2.length) {
            int a = p < v1.length ? Integer.valueOf(v1[p]) : 0;
            int b = p < v2.length ? Integer.valueOf(v2[p]) : 0;
            p++;
            if (a < b) {
                return -1;
            } else if(a > b){
                return 1;
            }
        }
        return 0;
    }
}
```
