### 解题思路

根据第一个字符，逐行逐字符判断。

- 若当前索引（index）已经等于了最小字符串的长度，则退出比较，公共前缀就是 firstStr(0, index)；
- 若当前索引下的字符串的前缀和第一个字符不匹配，则退出比较，公共前缀也是 firstStr(0, index);

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
         if (strs == null || strs.length == 0) {
            // empty strs
            return "";
        }
        // common length recorder
        int i = 0;
        // get first str
        String firstStr = strs[0];
        for (; i < firstStr.length(); i++) {
            // get the current char
            char toCompare = firstStr.charAt(i);
            boolean isAllEqual = true;
            for (int j = 1; j < strs.length; j++) {
                String str = strs[j];
                if (i >= str.length() || str.charAt(i) != toCompare) {
                    isAllEqual = false;
                    break;
                }
            }
            if (!isAllEqual) {
                break;
            }
        }
        return firstStr.substring(0, i);
    }
}
```