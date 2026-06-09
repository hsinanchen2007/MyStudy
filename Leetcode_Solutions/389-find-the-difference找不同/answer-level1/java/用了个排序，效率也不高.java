### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        char[] charS = s.toCharArray();
        char[] charT = t.toCharArray();
        Arrays.sort(charS);
        Arrays.sort(charT);
        for (int i = 0; i < charT.length; i++) {
            if (i == charS.length) {
                return charT[charS.length];
            }
            if (charS[i] != charT[i]) {
                return charT[i];
            }
        }
        return ' ';
    }
}
```