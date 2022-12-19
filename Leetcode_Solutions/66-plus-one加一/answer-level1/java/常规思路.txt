话不多说，直接上代码
```
class Solution {
    public int[] plusOne(int[] digits) {
        if (digits.length == 0) {return new int[]{1}; }
        int carry = 0;
        digits[digits.length - 1] += 1;
        for(int i = digits.length - 1; i >= 0; i--) {
            int digit = ( digits[i] + carry ) % 10;
            carry = ( digits[i] + carry) / 10;
            digits[i] = digit;
            if (carry == 0) { break; }
        }
        // if after the top digit plus one, the carry remain one
        if (carry == 1) {
            int[] result = new int[digits.length + 1];
            result[0] = 1;
            System.arraycopy(digits, 0, result, 1, result.length - 1);
            return result;
        }
        else { return digits; }
    }
}
```
