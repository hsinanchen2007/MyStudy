```
class Solution {
    public int countDigitOne(int n) {
        if (n <= 0) return 0;
        String str = String.valueOf(n);
        int digit = str.charAt(0) - '0';
        n = str.length() == 1 ? 0 : Integer.valueOf(str.substring(1));
        int res = getCnt(digit, str.length());
        if (digit == 1) {
            res += n + 1;
        }
        return res + countDigitOne(n);
    }

    private int getCnt(int digit, int bits) {
        if (digit == 0) return 0;
        int m = (int) Math.pow(10, bits-1) * digit;
        String str = String.valueOf(m);
        int highNum = str.charAt(0) - '0';
        int res = highNum == 1 ? 0 : m / highNum;
        return res + m / 10 * (str.length() - 1);
    }
}
```