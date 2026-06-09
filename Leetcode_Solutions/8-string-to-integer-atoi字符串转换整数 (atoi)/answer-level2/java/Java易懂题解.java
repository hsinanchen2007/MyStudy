```java
public int myAtoi(String str) {
        // str is null or empty
        if (str == null || (str = str.trim()).isEmpty()) {
            return 0;
        }

        int start;
        char sign;
        char firstChar = str.charAt(0);
        if (firstChar == '+' || firstChar == '-') {
            start = 1;
            sign = firstChar;
        } else if (firstChar >= '0' && firstChar <= '9') {
            start = 0;
            sign = '+';
        } else {
            // invalid start char
            return 0;
        }

        int ans = 0;
        for (int i = start; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c < '0' || c > '9') {
                break;
            }
            int num = c - '0';
            if ((Integer.MAX_VALUE - num) / 10 < ans) {
                return sign == '+' ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            ans = ans * 10 + num;
        }
        return sign == '+' ? ans :  -ans;
    }
```
