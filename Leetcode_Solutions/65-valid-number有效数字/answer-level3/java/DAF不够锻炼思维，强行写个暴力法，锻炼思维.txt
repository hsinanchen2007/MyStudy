话不多说，直接上代码：
```java
class Solution {
    public boolean isNumber(String s) {
        char[] chars = s.toCharArray();
        if (chars.length == 0) {
            return false;
        }
        int i = 0;
        if (isWhitespaceChar(chars[i])) {
            while (i < chars.length && isWhitespaceChar(chars[i])) {
                i++;
            }
            if (i == chars.length) {
                return false;
            }
        }
        if (isSignChar(chars[i])) { // +
            i++;
        }
        if (i == chars.length) {
            return false;
        }
        if (!isDigitChar(chars[i]) && !isPointChar(chars[i])) {
            return false;
        }

        if (isDigitChar(chars[i])) { // +3

            while (i < chars.length && isDigitChar(chars[i])) {
                i++;
            }
            if (i == chars.length) {
                return true;
            }
        }
        if (isPointChar(chars[i])) { // +3.
            i++;
            if (i == chars.length) {
                if ((i - 2 >= 0) && isDigitChar(chars[i - 2])) {
                    return true;
                }
                return false;
            } else if (isDigitChar(chars[i])) {
                while (i < chars.length && isDigitChar(chars[i])) {
                    i++;
                }
                if (i == chars.length) {
                    return true;
                } else if (isWhitespaceChar(chars[i])) {
                    return startWhitespaceChar(i, chars);
                } else if (isExpChar(chars[i])) {
                    i++;
                    return afterExpChar(i, chars);
                }
            } else if (isWhitespaceChar(chars[i])) {
                if ((i - 2 >= 0) && isDigitChar(chars[i - 2])) {
                    return startWhitespaceChar(i, chars);
                }
                return false;
            } else if (isExpChar(chars[i])) {
                if ((i - 2 < 0) || !isDigitChar(chars[i - 2])) {
                    return false;
                }
                // +3.e
                i++;
                return afterExpChar(i, chars);
            } else
                return false;
        } else if (isExpChar(chars[i])) { // +3e
            i++;
            return afterExpChar(i, chars);
        } else if (isWhitespaceChar(chars[i])) {
            return startWhitespaceChar(i, chars);
        } else
            return false;
        return false;
    }

    private boolean isSignChar(char c) {
        return c == '+' || c == '-';
    }

    private boolean isDigitChar(char c) {
        return c >= '0' && c <= '9';
    }

    private boolean isExpChar(char c) {
        return c == 'e';
    }

    private boolean isPointChar(char c) {
        return c == '.';
    }

    private boolean isWhitespaceChar(char c) {
        return c == ' ';
    }

    private boolean afterExpChar(int i, char[] chars) {
        if (i == chars.length) {
            return false;
        }
        if (isSignChar(chars[i])) {
            // []e+
            i++;
        }
        if (i == chars.length) {
            return false;
        }
        if (isDigitChar(chars[i])) {
            // []e+123
            while (i < chars.length && isDigitChar(chars[i])) {
                i++;
            }
            if (i == chars.length) {
                return true;
            }
            if (isWhitespaceChar(chars[i])) {
                return startWhitespaceChar(i, chars);
            } else
                return false;
        } else
            return false;
    }

    private boolean startWhitespaceChar(int i, char[] chars) {
        while (i < chars.length && isWhitespaceChar(chars[i])) {
            i++;
        }
        if (i == chars.length) {
            return true;
        }
        return false;
    }
}
```