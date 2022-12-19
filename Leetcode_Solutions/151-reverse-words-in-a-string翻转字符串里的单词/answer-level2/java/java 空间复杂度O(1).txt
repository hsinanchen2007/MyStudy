### 解题思路

首先将字符串整体反向，然后将其中每个单词原地旋转，最后删除多余空格。

题目中要求C语言达到空间O(1)的解法原地旋转数组，但java中String为不可变对象，对String的修改将会生成新的String对象，所以将String转化为char[]，在char[]上操作。且本解法中，不使用任何语言相关的api。

### 代码

```java
public class Solution {
    public String reverseWords( String s ){
        char[] chars = new char[s.length()];
        s.getChars(0, s.length(), chars, 0);

        //旋转char[]
        reverseChars(chars);

        //采用flag标记当前状态。
        //当扫描到字符串结尾或空格，且处于单词状态中时，说明扫描到了单词结尾。
        //此时调用reverseWord反转单词
        int start = 0;
        boolean word = false;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != ' ' && !word) {
                word = true;
                start = i;
            }
            if ((i == chars.length - 1 || chars[i + 1] == ' ') && word) {
                word = false;
                reverseWord(chars,start,i);
            }
        }

        //最后调用removeSpaces方法删除空格并返回新的长度
        return new String(chars, 0, removeSpaces(chars));
    }

    private void reverseChars( char[] chars ){
        char tmp;
        for (int i = 0, j = chars.length - 1; i < j; i++, j--) {
            tmp = chars[i];
            chars[i] = chars[j];
            chars[j] = tmp;
        }
    }

    private void reverseWord( char[] chars, int left, int right ){
        char tmp;
        while (left < right) {
            tmp = chars[left];
            chars[left++] = chars[right];
            chars[right--] = tmp;
        }
    }

    private int removeSpaces(char[] chars){
        int content = 0;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != ' ') {
                if (content != 0) {
                    chars[content++] = ' ';
                }
                while (i < chars.length && (chars[i] != ' ')) {
                    chars[content++] = chars[i++];
                }
            }
        }
        return content;
    }
}
```
执行用时 :3 ms, 在所有 Java 提交中击败了70.64%的用户