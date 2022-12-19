### 解题思路
    我们都熟悉二进制和十进制的互转方法，那么字母序号到数字顾名思义，二十六进制转十进制。我们假设二十六进制S有n位（n > 0），则：
    result = Sn * (26 ^ (n-1)) + Sn-1 * (26 ^ (n - 2)) + ... + S1 * (26 ^ 0);

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        char[] charset = s.toCharArray();
        int sum = 0;
        for (int i = 0; i < charset.length; i++) {
            int ascVal = (int) charset[i];
            int digit = 0;
            if (ascVal > 96) {
                digit = ascVal - 96;
            } else {
                digit = ascVal - 64;
            }
            int square = charset.length - i - 1;
            double squareRes = digit * Math.pow(26, square);
            sum += (int) squareRes;
        }
        return sum;
    }
}
```