首先遍历字符串所有字符，统计大写字母个数。
然后分三种情况：

1.大写字母个数为0，或者大写字母个数为字符串长度，说明此时为全大写或者全小写，返回true。

2.首字母大写，大写字母个数为1，说明此时只有首字母大写，返回true。

3.其余返回false。
此解击败91%的人，大家有更好的意见可以共同学习讨论~
```
public class Solution {
    public boolean detectCapitalUse(String word) {
        int len = word.length();
        int count = 0;
        for (int i=0; i<len; i++) {
            if (isUpperCase(word.charAt(i))) {
                count++;
            }
        }
        if (count == 0 || count == len) {
            return true;
        } else if (isUpperCase(word.charAt(0)) && count == 1) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isUpperCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
}
```
