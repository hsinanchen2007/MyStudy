### 解题思路

辗转相除法

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1 != null && str2 != null && str1.length() > 0 && str2.length() > 0) {

            String longStr = str2;
            String shortStr = str1;
            if (str1.length() > str2.length()) {
                longStr = str1;
                shortStr = str2;
            }

            while (shortStr.length() > 0) {
                if (!longStr.contains(shortStr)) {
                    return "";
                }
                String tmp = longStr.replace(shortStr, "");
                longStr = shortStr;
                shortStr = tmp;
            }

            return longStr;
        }
        return "";
    }
}
```