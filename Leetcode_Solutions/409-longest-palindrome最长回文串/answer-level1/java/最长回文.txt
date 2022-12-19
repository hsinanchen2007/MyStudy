### 解题思路
此处撰写解题思路
字符串，就是对字符的处理，记录字符出现的次数，很多算法都是围绕着字符次数而设计的
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] charCounts = new int[256];
        for(char c : s.toCharArray()) {
            charCounts[c] ++;
        }
        int returnPlain = 0;
        for(int charCount : charCounts) {
            returnPlain +=  (charCount / 2) * 2;
        }
        if(returnPlain < s.length()) {
            returnPlain ++;
        }
        return returnPlain;
    }
}
```