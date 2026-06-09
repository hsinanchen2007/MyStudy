### 解题思路
取得最长的公共前缀，第一反应就是将所有字符串排成一列，字符一一对应，假设有一条垂直的线，从第一个字符依次扫过去，直到扫到**最短字符串的最后一个字符**或者**开始有不同的字符出现**时，即找到了最长的公共前缀。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (null == strs || strs.length == 0) return "";
        String first = strs[0];
        char[] firstArray = first.toCharArray();
        for (int i = 0; i < firstArray.length; i++) {
            for (int j = 1; j < strs.length; j++) {
                if (i > strs[j].length() - 1 || firstArray[i] != strs[j].charAt(i)) {
                    return first.substring(0, i);
                }
            }
        }

        return first;
    }
}
```