### 解题思路
解题思路：找出6种特殊情况的字符串，把他们的值相加后剔除，形成一个新的不含特殊情况的字符串，对新字符进行遍历即可，但是消耗资源较多

### 代码

```java
class Solution {
    public int romanToInt(String s) {
 int sum = 0;
        int count = 0;

        int flag1 = 0;
        int flag2 = 0;

        while (true) {

            if (s.indexOf("IV") >= 0) {
                sum += 4;
                s = s.replaceFirst("IV", "");
                count++;
            }

            if (s.indexOf("IX") >= 0) {
                sum += 9;
                s = s.replaceFirst("IX", "");
                count++;
            }
            if (s.indexOf("XL") >= 0) {
                sum += 40;
                s = s.replaceFirst("XL", "");
                count++;
            }
            if (s.indexOf("XC") >= 0) {
                sum += 90;
                s = s.replaceFirst("XC", "");
                count++;
            }
            if (s.indexOf("CD") >= 0) {
                sum += 400;
                s = s.replaceFirst("CD", "");
                count++;
            }
            if (s.indexOf("CM") >= 0) {
                sum += 900;
                s = s.replaceFirst("CM", "");
                count++;
            }

            flag1 = flag2;
            flag2 = count;

            if (flag1 == flag2) {

                char[] chars = s.toCharArray();
                for (int i = 0; i < chars.length; i++) {

                    if (chars[i] == 'I') sum += 1;
                    if (chars[i] == 'V') sum += 5;
                    if (chars[i] == 'X') sum += 10;
                    if (chars[i] == 'L') sum += 50;
                    if (chars[i] == 'C') sum += 100;
                    if (chars[i] == 'D') sum += 500;
                    if (chars[i] == 'M') sum += 1000;

                }

                return sum;

            }


        }
    }
}
```