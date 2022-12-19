### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public int myAtoi(String str) {
        if (Objects.isNull(str) || 0 == str.length())
            return 0;

        int isNegative = 1;
        int beginIndex = 0;
        int endIndex = 0;
        for (; beginIndex < str.length(); ++beginIndex) {
            if (str.charAt(beginIndex) != ' ')
                break;
        }

        if (beginIndex >= str.length() || ('-' != str.charAt(beginIndex) && '+' != str.charAt(beginIndex) && !Character.isDigit(str.charAt(beginIndex))))
            return 0;

        if ('-' == str.charAt(beginIndex) || '+' == str.charAt(beginIndex)) {
            isNegative = '-' == str.charAt(beginIndex) ? -1 : 1;
            ++beginIndex;
        }

        long num = 0;
        for (endIndex = beginIndex; endIndex < str.length(); ++endIndex) {
            if (!Character.isDigit(str.charAt(endIndex)))
                break;
            num = 10*num + str.charAt(endIndex) - '0';

            if (num > Integer.MAX_VALUE) {
                break;
            }
        }

        num =  isNegative * num;

        if (num > Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        if (num < Integer.MIN_VALUE)
            return Integer.MIN_VALUE;

        return (int)num;
    }
}
```