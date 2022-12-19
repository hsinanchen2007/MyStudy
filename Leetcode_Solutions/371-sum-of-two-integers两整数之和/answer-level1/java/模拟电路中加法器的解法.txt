```
public int getSum(int a, int b) {
        int digit = 1;
        int sum = 0;
        int carry = 0;
        while (digit != 0) {
            int a_digit = a & digit;
            int b_digit = b & digit;
            int oneDigitResult = a_digit ^ b_digit;
            sum |= oneDigitResult ^ carry;
            carry = (a_digit & b_digit) | oneDigitResult & carry;
            digit <<= 1;
            carry <<= 1;
        }
        return sum;
    }
```