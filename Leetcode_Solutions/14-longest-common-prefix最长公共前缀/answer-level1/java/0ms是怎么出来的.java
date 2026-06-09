### 解题思路
此处撰写解题思路
贪婪思维，找出长度最小的字段。然后一一对比，再然后剪短字符
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length < 1) {
            return "";
        }
        String minStr = strs[0];
        for (int i = 1; i < strs.length; i++) {
            if (minStr.length() > strs[i].length()) {
                minStr = strs[i];
            }
        }
        while (minStr.length() > 0) {
            for (int i = 0; i < strs.length; i++) {
                if (!strs[i].startsWith(minStr)) {
                    minStr = minStr.substring(0, minStr.length() - 1);
                    break;
                }
                if (i == strs.length - 1) {
                    return minStr;
                }
            }
        }
        return "";
    }
}
```