```java
class Solution {
    public boolean isNumber(String s) {
        int allowE = 1;
        int allowDot = 1;
        boolean dotE = false;
        int pre = -1; //行首-1，数字0，e1，+/-2，.3
        s = s.trim();
        if (s.length() == 0 || (s.length() == 1 && !isDigit(s.charAt(0)))) {
            return false;
        }
        if (s.charAt(s.length() - 1) != '.' && !isDigit(s.charAt(s.length() - 1))) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            if (!isDigit(a) && !isLegalChar(a)) {
                return false;
            }
            if (isDigit(a)) {
                pre = 0;
            }
            if (a == 'e') {
                if ((pre != 0 && pre != 3) || allowE == 0) {
                    return false;
                }
                if (pre == 3 && dotE) {
                    return false;
                }
                allowE = 0;
                allowDot = 0;
                pre = 1;
            }
            if (a == '+' || a == '-') {
                if (pre != -1 && pre != 1) {
                    return false;
                }
                pre = 2;
            }
            if (a == '.') {
                if ((pre != 0 && pre != -1 && pre != 2) || allowDot == 0) {
                    return false;
                }
                dotE = (pre == -1 || pre == 2);
                allowDot = 0;
                pre = 3;
            }
        }
        return !dotE || s.charAt(s.length() - 1) != '.';
    }

    private boolean isDigit(char a) {
        return a >= '0' && a <= '9';
    }

    private boolean isLegalChar(char a) {
        return a == '+' || a == '-' || a == 'e' || a == '.';
    }

}
```