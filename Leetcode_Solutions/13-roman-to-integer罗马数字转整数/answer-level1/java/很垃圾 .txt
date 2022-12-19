### 解题思路
垃圾就完事了 

### 代码

```java
class Solution {
    public int romanToInt(String s) {
         int lengtn = s.length();
        int k = 1;
        int sum = 0;
        for (int i = lengtn - 1; i >= 0; i--) {
            switch (s.charAt(i)) {
                case 'I':
                    if ((i + 1) < lengtn && s.charAt(i + 1) == 'V') {
                        sum -= 1;
                    } else if ((i + 1) < lengtn && s.charAt(i + 1) == 'X') {
                        sum -= 1;
                    } else {
                        sum += 1;
                    }
                    break;
                case 'V':
                    if ((i + 1) < lengtn && s.charAt(i + 1) == 'X') {
                        sum -= 1 * 5;
                    } else if ((i + 1) < lengtn && s.charAt(i + 1) == 'L') {
                        sum -= 1 * 5;
                    } else {
                        sum += 1 * 5;
                    }
                    break;
                case 'X':
                    if ((i + 1) < lengtn && s.charAt(i + 1) == 'L') {
                        sum -= 1 * 10;
                    } else if ((i + 1) < lengtn && s.charAt(i + 1) == 'C') {
                        sum -= 1 * 10;
                    } else {
                        sum += 1 * 10;
                    }
                    break;
                case 'L':
                    if ((i + 1) < lengtn && s.charAt(i + 1) == 'C') {
                        sum -= 1 * 50;
                    } else if ((i + 1) < lengtn && s.charAt(i + 1) == 'D') {
                        sum -= 1 * 50;
                    } else {
                        sum += 1 * 50;
                    }
                    break;
                case 'C':
                    if ((i + 1) < lengtn && s.charAt(i + 1) == 'D') {
                        sum -= 1 * 100;
                    } else if ((i + 1) < lengtn && s.charAt(i + 1) == 'M') {
                        sum -= 1 * 100;
                    } else {
                        sum += 1 * 100;
                    }
                    break;
                case 'D':
                    sum += 1 * 500;
                    break;
                case 'M':
                    sum += 1 * 1000;
                    break;
            }
        }


        return sum;
        
    }
}
```