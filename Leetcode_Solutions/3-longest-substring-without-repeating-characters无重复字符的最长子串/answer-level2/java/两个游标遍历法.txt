### 解题思路
通过两个游标从左到右1次遍历完成，复杂的O(n)：
1、游标1，标识从源字符串中截取的起始位置，并随着找到重复的字符是不断叠加，注意：这里是关键；
2、游标2，标识下一个字符，不到对比，增加；
3、结果取result和截取的字串的最大值。

### 代码

```java
class Solution {
    public static int lengthOfLongestSubstring(String s) {
        if ("".equals(s)) {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        int indexStart = 0;
        int indexEnd = 1;
        int result = 0;
        // 取第一个字符
        String tmpStr = s.substring(indexStart, indexEnd);
        // 循环检测下一个字符是否在字符串中，如果找到，截取该位置之后的字符
        while (indexEnd != s.length()) {
            int indexFound = tmpStr.indexOf(s.charAt(indexEnd++));
            if (indexFound == -1) {
                // 没有找到，继续找
                tmpStr = s.substring(indexStart, indexEnd);
            } else {
                // 找到了
                result = Math.max(result, tmpStr.length());
                indexStart += indexFound + 1;
                tmpStr = s.substring(indexStart, indexEnd);
            }
        }
        return Math.max(result, tmpStr.length());
    }
}
```