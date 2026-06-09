最简单的就是遍历整个串的每个字符，针对特殊的6种情况进行额外判断即可；特殊情况的就是多取下一位。

```
public int romanToInt(String s) {
        int num = 0;
        int i = 0;
        int len = s.length();
        while (i < len) {
            char ch = s.charAt(i);
            switch (ch) {
                case 'I':
                    if (i + 1 < len) {
                        ch = s.charAt(i + 1);
                        if (ch == 'V') {
                            num += 4;
                            i++;
                        } else if (ch == 'X') {
                            num += 9;
                            i++;
                        } else {
                            num += 1;
                        }
                    } else {
                        num += 1;
                    }
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'X':
                    if (i + 1 < len) {
                        ch = s.charAt(i + 1);
                        if (ch == 'L') {
                            num += 40;
                            i++;
                        } else if (ch == 'C') {
                            num += 90;
                            i++;
                        } else {
                            num += 10;
                        }
                    } else {
                        num += 10;
                    }
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'C':
                    if (i + 1 < len) {
                        ch = s.charAt(i + 1);
                        if (ch == 'D') {
                            num += 400;
                            i++;
                        } else if (ch == 'M') {
                            num += 900;
                            i++;
                        } else {
                            num += 100;
                        }
                    } else {
                        num += 100;
                    }
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'M':
                    num += 1000;
                    break;
                default:
                    break;
            }
            i++;
        }
        return num;
    }
```
