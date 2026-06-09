### 解题思路
这种首尾交换的自然想到双指针，如果你想不到，只有一个可能，做的题目还不够多，读书破万卷下笔如有神，哈哈哈

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        if (S == null || S.length() < 2) {
            return S;
        }
        char[] chars = S.toCharArray();
        int begin = 0;
        int end = chars.length - 1;

        while (end > begin) {
            if (Character.isLetter(chars[begin]) && Character.isLetter(chars[end])) {
                char tmp = chars[begin];
                chars[begin] = chars[end];
                chars[end] = tmp;
                begin++;
                end--;
            } else if (Character.isLetter(chars[begin])) {
                end--;
            } else if (Character.isLetter(chars[end])) {
                begin++;
            } else {
                begin++;
                end--;
            }
        }
        return String.valueOf(chars);
    }
}
```