### 解题思路
this question is mainly about the consideration of carry numbers when the last one is 9, it should then changed into 0 and check if its left side digit is 9. when all of the digits in this array are 9, then it should add one more digit, like 999--1000.

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int digit = digits.length - 1; digit >= 0; digit--) {
            if (digits[digit] != 9) {
                digits[digit] += 1;
                return digits;
            } else {
                digits[digit] = 0;
            }
        }
        int[] newDigits = new int[digits.length + 1];
        newDigits[0] = 1;
        return newDigits;
    }
}
```