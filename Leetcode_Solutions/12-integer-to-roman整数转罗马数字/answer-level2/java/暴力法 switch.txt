```
class Solution {
    public String intToRoman(int num) {
        char[] signs = new char[]{'I', 'V', 'X', 'L', 'C', 'D',  'M'};
        String[] newsigns = new String[]{"IV", "IX", "XL", "XC", "CD", "CM"};
                                        // 4,9,40,90,400,900
        int[] values = new int[]{  1,   5,   10,  50, 100, 500,  1000};
        String ans = "";
        int maxDigit = 6;
        while(maxDigit > -1){
            int mul = num / values[maxDigit];
            num %= values[maxDigit];
            switch (mul){                
                case 8:
                    ans += signs[maxDigit + 1];
                    ans += signs[maxDigit];
                    ans += signs[maxDigit];
                    ans += signs[maxDigit];
                    break;
                case 7:
                    ans += signs[maxDigit + 1];
                    ans += signs[maxDigit];
                    ans += signs[maxDigit];
                    break;
                case 6:
                    ans += signs[maxDigit + 1];
                    ans += signs[maxDigit];
                    break;
                case 9:
                    ans += newsigns[maxDigit + 1];
                    break;
                case 5:
                    ans += signs[maxDigit + 1];
                    break;
                case 4:
                    ans += newsigns[maxDigit];
                    break;
                case 3:
                    ans += signs[maxDigit];
                case 2:
                    ans += signs[maxDigit];
                case 1:
                    ans += signs[maxDigit];
                    break;
                case 0:
                    break;
            }
            maxDigit -= 2;
        }
        return ans;
    }
}
```
