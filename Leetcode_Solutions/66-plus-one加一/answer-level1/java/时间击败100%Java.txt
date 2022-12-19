```
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int add = 0;//进位
        int first = 1;
        for (int i = len - 1; i >= 0; i--) {
            int val = (digits[i] + first + add) % 10;
            add = (digits[i] + first + add) / 10;
            digits[i] = val;
            first = 0;
        }
        if(add > 0){
            int[] res = new int[len + 1];
            System.arraycopy(digits, 0, res, 1, len);
            res[0] = add;
            return res;
        }
        return digits;
    }
}
```
