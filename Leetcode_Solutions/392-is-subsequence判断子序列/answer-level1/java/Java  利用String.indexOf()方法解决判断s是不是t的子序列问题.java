### 解题思路
熟记字符串String的常用API！！！
题目需要：查看某个字符某个位置开始之后是否存在某个字符，并返回对应的index。
即String.indexOf(char c, int index);返回-1表示不存在该字符。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() > t.length()) {
            return false;
        }
        int j = -1;
        // s为子序列，t为较长的字符串
        // 遍历s的每个字符，看是否在t中存在，且需要从上次找到字符在t中index的下一个开始找
        for (int i = 0; i < s.length(); i++) {
            // 第一次从index0开始，下次从这次找到的下标j的下一个开始
            // 因此为了统一初始化j为-1解决j+1为0这个初始index特殊性
            j = t.indexOf(s.charAt(i), j + 1); 
            if (j == -1) {
                return false;
            }
        }

        return true;
    }
}
```