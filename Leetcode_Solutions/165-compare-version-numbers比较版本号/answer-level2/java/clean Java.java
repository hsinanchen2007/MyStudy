### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] str1 = version1.split("\\.");
        String[] str2 = version2.split("\\.");

        for (int i = 0; i < Math.max(str1.length, str2.length); i++) {
            int v1 = i < str1.length ? Integer.parseInt(str1[i]) : 0;
            int v2 = i < str2.length ? Integer.parseInt(str2[i]) : 0;
            if (v1 > v2) {
                return 1;
            }else if (v2 > v1) {
                return -1;
            }
        }
        return 0;
    }
}
```