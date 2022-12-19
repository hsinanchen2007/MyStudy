### 解题思路
很容易想到的一种思路是,将数组中的第一个字符串的子串依次取出,然后不断的遍历原数组去匹配,如果中途匹配失败了,那么说明上一个子串就是最长子串.如果都匹配上了,那么第一个字符串就是最长子串.

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
      if (strs == null || strs.length == 0) {
            return "";
        }
        String shortStr = strs[0];
        boolean flag = true;
        for (int i = 0; i < shortStr.length(); i++) {
            String childStr = shortStr.substring(0, i + 1);
            for (String str : strs) {
                if (!str.startsWith(childStr)) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                return shortStr.substring(0, i);
            }
        }
        return shortStr;
    }
}
```