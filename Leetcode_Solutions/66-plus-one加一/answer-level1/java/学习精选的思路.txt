### 解题思路
考虑两种情况:
    1 末位是9
        末位+1,取0.进一位+1,返回数组
        若每一位都是9,则每一位都将变成0,数组长度+1,将第0位赋值为1.
    2 末位不是9
        末位+1,返回数组

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
```