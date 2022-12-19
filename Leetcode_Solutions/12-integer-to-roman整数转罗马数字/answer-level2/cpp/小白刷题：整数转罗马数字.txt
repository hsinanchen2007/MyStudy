从低位到高位开始，按照规则构造每一位，最后拼到一起即可

代码：
```
class Solution {
public:
    string intToRoman(int num) {
        string num_arr[4] = {""};
        for (int i = 3; i >= 0; i--) {
            int digit = num % 10;
            if (i == 3) {
                if (digit == 4)
                    num_arr[i] = "IV";
                else if (digit == 9)
                    num_arr[i] = "IX";
                else {
                    num_arr[i].append(digit / 5, 'V');
                    num_arr[i].append(digit % 5, 'I');
                }
            }
            else if (i == 2) {
                if (digit == 4)
                    num_arr[i] = "XL";
                else if (digit == 9)
                    num_arr[i] = "XC";
                else {
                    num_arr[i].append(digit / 5, 'L');
                    num_arr[i].append(digit % 5, 'X');
                }
            }
            else if (i == 1) {
                if (digit == 4)
                    num_arr[i] = "CD";
                else if (digit == 9)
                    num_arr[i] = "CM";
                else {
                    num_arr[i].append(digit / 5, 'D');
                    num_arr[i].append(digit % 5, 'C');
                }
            }
            else {
                num_arr[i].append(digit, 'M');
            }
            num = num / 10;
        }
        return num_arr[0] + num_arr[1] + num_arr[2] + num_arr[3];
    }
};
```
