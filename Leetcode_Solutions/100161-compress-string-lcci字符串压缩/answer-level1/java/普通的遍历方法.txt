### 解题思路
 把字符串转换成数组，遍历这个数组，设置一个标志位，当后一个数和前一个数相等时，标志位加一，不相等时，将当前累积的标志位添加到新的StringBuilder中，并把后一个字符加入到StringBuilder中，循环这个过程。
 初始化时需要把数组的第一个字符作为默认值放到 currentChar 中，这样可以省掉判断第一步的逻辑，同样因为在循环之外初始化，所以当循环开始时第一次必定和初始值相当，所以标志位 i 的初始值设置为0,之后的值因为在循环中已经被计算，所以初始设为1.
 开头考虑空字符串，做特殊处理。
### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S.length()<1) {
            return "";
        }
        char[] chars = S.toCharArray();
        char currentChar=chars[0];
        StringBuilder expected = new StringBuilder();
        expected.append(chars[0]);
        int i = 0;
        for (char aChar : chars) {
            if (currentChar==aChar) {
                i++;
            } else {
                expected.append(i);
                expected.append(aChar);
                currentChar=aChar;
                i=1;
            }
        }
        expected.append(i);
        if (expected.length()>=S.length()) {
            return S;
        } else {
           return expected.toString();
        }
    }
}
```