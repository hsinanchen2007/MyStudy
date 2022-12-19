### 解题思路
首先用第一个字符串来作为参考，因为是公共前缀，所以第一个肯定也会包含了公共前缀，

外部从前往后遍历第一个字符串的每个字符，内部遍历所有字符串，如果所有字符串在相同位置都有该字符，则前缀字符拼接上该字符，
如果有一个字符串在该位置没有该字符，则返回前缀字符串

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
         return "";
      }

      String prefix = "";
      // 拿第一个字符串作为参考
      String firstStr = strs[0];

      for(int i = 0; i < firstStr.length(); i++) {
         char c = firstStr.charAt(i);

         for(String str : strs) {
            if(str.length() < i + 1 || str.charAt(i) != c) {
               return prefix;
            }
         }

         prefix += c;
      }

      return prefix;
    }
}
```