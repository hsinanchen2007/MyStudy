### 解题思路
朴素的思路，直接看代码~

### 代码

```java
class Solution {

    private boolean isNum(char c) {
        return c >= '0' && c <= '9';
    }

    private boolean isValid(char c) {
        return c == '-' || c == '+' || (c >= '0' && c <= '9');
    }

    public int myAtoi(String str) {
        if (str == null || str.length() == 0) {
            return 0;
        }

        int index = 0;
        while(index < str.length() && str.charAt(index) == ' ') {
            index++;
        }
        if (index == str.length()) {
            return 0;
        }
        if (!isValid(str.charAt(index))) {
            return 0;
        }

        int symNum = str.charAt(index) == '-' ? -1 : 1;
        if (str.charAt(index) == '-' || str.charAt(index) == '+') {
            index++;
        }

        long nums = 0;
        while(index < str.length() && isNum(str.charAt(index))) {
            nums = 10 * nums + (str.charAt(index) - '0');
            index++;
            long trueNum = symNum * nums;
            if (trueNum >= Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (trueNum <= Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }
        return (int)(symNum * nums);
    }
}
```