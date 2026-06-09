[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_58_lengthOfLastWord.java)

```java
    /**
     * 解题思路：
     * 从s的最后一个开始遍历，遇到首个非空的字母开始计数到下一个为空的时候停止
     *
     * @param s
     * @return
     */
    public int lengthOfLastWord(String s) {
        int startIndex = -1, endIndex = -1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (startIndex != -1 && s.charAt(i) == ' ') {
                endIndex = i;
                break;
            }
            if (startIndex == -1 && s.charAt(i) != ' ') {
                startIndex = i;
            }
        }
        if (startIndex == -1) {
            return 0;
        }
        return startIndex - endIndex;
    }
```