### 解题思路
if else hell...
### 代码

```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] version1Str = version1.split("\\.");
        String[] version2Str = version2.split("\\.");
        int[] version1Num = {0, 0, 0, 0};
        int[] version2Num = {0, 0, 0, 0};
        for (int i = 0; i < 4; i++) {
            version1Num[i] = i < version1Str.length ? Integer.valueOf(version1Str[i]) : 0;
            version2Num[i] = i < version2Str.length ? Integer.valueOf(version2Str[i]) : 0;
        }

        if (version1Num[0] == version2Num[0]) {
            if (version1Num[1] == version2Num[1]) {
                if (version1Num[2] == version2Num[2]) {
                    if (version1Num[3] == version2Num[3]) {
                        return 0;
                    } else {
                        return version1Num[3] > version2Num[3] ? 1 : -1;
                    }
                } else {
                    return version1Num[2] > version2Num[2] ? 1 : -1;
                }
            } else {
                return version1Num[1] > version2Num[1] ? 1 : -1;
            }
        } else {
            return version1Num[0] > version2Num[0] ? 1 : -1;
        }
    }
}
```