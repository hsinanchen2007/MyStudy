### 解题思路
设定一个carry记录是否应该额外+1。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int i = digits.length - 1;
        while(i >= 0){
            int sum = digits[i] + carry;
            if (sum >= 10){
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }

            digits[i--] = sum;

            if (carry == 0){
                break;
            }
        }

        if (carry == 1){
            int[] new_digits = new int[digits.length + 1];
            new_digits[0] = 1;
            for (i = 1; i < new_digits.length; i++){
                new_digits[i] = digits[i-1];
            }
            return new_digits;
        } else {
            return digits;
        }
    }
}
```