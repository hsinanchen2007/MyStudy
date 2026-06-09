### 解题思路
利用refresh去掉括号，利用doCalculate计算无括号的公式。
整个计算先去掉最里层的括号，然后依次去掉外层括号，笨办法。

### 代码

```java
class Solution {
     private static final char LEFT_BRACKET = '(';
    private static final char RIGHT_BRACKET = ')';
    private static final char PLUS_SIGN = '+';
    private static final char MINUS_SIGN = '-';

     public int calculate(String s) {
        String text = refresh(s);
        return doCalculate(text);
    }

    private String refresh(String text) {
        for (int start = text.lastIndexOf(LEFT_BRACKET); start > -1; start = text.lastIndexOf(LEFT_BRACKET)) {
            //截取括号中的字符串
            int end = text.indexOf(RIGHT_BRACKET, start);
            String tmp = text.substring(start + 1, end);
            //转换成新的字符串
            int num = doCalculate(tmp);
            tmp = String.valueOf(num);
            if (start != 0 && num < 0) {
                start--;
                if (text.charAt(start) == MINUS_SIGN) {
                    tmp = PLUS_SIGN + String.valueOf(-num);
                }
            }
            text = text.substring(0, start) + tmp + text.substring(end + 1);
        }
        return text;
    }

    private int doCalculate(String text) {
        int index = text.indexOf(PLUS_SIGN);
        if (index > -1) {
            return doCalculate(text.substring(0, index)) + doCalculate(text.substring(index + 1));
        }
        index = text.lastIndexOf(MINUS_SIGN);
        if (index > 0) {
            return doCalculate(text.substring(0, index)) - doCalculate(text.substring(index + 1));
        }
        return Integer.valueOf(text.trim());
    }

}
```