### 解题思路
思路很简单，暴力破解

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        if (strs.length == 1) {
            return strs[0];    
        }

        // 先定义一个最长公共前缀,并将数组的第一个字符串赋给它
        String maxSameString = strs[0];

        // 然后去循环
        for (int i = 1; i < strs.length; i++) {
            // 获取两个字符串的共同前缀
            String maxString = getMaxSameString(maxSameString, strs[i]);
            // 将长度更短的值赋给maxSameString
            maxSameString = maxString.length() > maxSameString.length() ? maxSameString: maxString;
        }
        return maxSameString;
    }

    public String getMaxSameString(String str1, String str2) {
        StringBuilder stringBuilder = new StringBuilder();
        // 获取长度更短的
        int n = str1.length() > str2.length() ? str2.length() : str1.length();
        for (int i = 0; i < n; i++) {
            // 如果这两个相同
            if (str1.charAt(i) == str2.charAt(i)) {
                stringBuilder.append(str1.charAt(i));
                // 如果不同则直接跳出循环
            } else {
                break;
            }
        }
        return stringBuilder.toString();
    }
} 
```