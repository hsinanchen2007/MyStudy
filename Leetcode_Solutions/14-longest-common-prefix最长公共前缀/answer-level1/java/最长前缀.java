### 解题思路
最长公共前缀，要么为空字符串，要么第一个元素也包含，那么不需要缓存数据，也不需要保存字符串，只需要记录下最长长度；

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
if (strs == null || strs.length == 0) {
            return "";
        }
        int max = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            max = Math.min(max, strs[i].length());
            for (int j = 0; j < max; j++) {
                if (strs[0].charAt(j) != strs[i].charAt(j)) {
                    max = j;
                    break;
                }
            }
        }
        return strs[0].substring(0, max);
    }
}
```