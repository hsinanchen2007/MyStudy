java 版，switch case 中套 if else

```java
class Solution {
    public int romanToInt(String s) {
        /* 
            I, X, C 最多三个连续
            数字大的字符在前面 
        */

        /*
            我们有结论：
            如果 I 后有 V, X 就表示 4 和 9
            如果 X 后有 L, C 就表示 40 和 100
            如果 C 后有 D, M 就表示 400 和 1000
        */

        char[] charArr = s.toCharArray();
        int sum = 0;
        for (int i = 0; i < charArr.length; i++) {
            switch (charArr[i]) {
                case 'I' :
                    if (i + 1 < charArr.length && charArr[i+1] == 'V') {
                        sum += 4;
                        i++;
                    }
                    else if (i + 1 < charArr.length && charArr[i+1] == 'X') {
                        sum += 9;
                        i++;
                    }
                    else {
                        sum++;
                    }
                    break;
                case 'V' :
                    sum += 5;
                    break;
                case 'X' :
                    if (i + 1 < charArr.length && charArr[i+1] == 'L') {
                        sum += 40;
                        i++;
                    }
                    else if (i + 1 < charArr.length && charArr[i+1] == 'C') {
                        sum += 90;
                        i++;
                    }
                    else {
                        sum += 10;
                    }
                    break;
                case 'L' :
                    sum += 50;
                    break;
                case 'C' :
                    if (i + 1 < charArr.length && charArr[i+1] == 'D') {
                        sum += 400;
                        i++;
                    }
                    else if (i + 1 < charArr.length && charArr[i+1] == 'M') {
                        sum += 900;
                        i++;
                    }
                    else {
                        sum += 100;
                    }
                    break;
                case 'D' :
                    sum += 500;
                    break;
                case 'M' :
                    sum += 1000;
                    break;
            }
        }
        return sum;
    }
}
```