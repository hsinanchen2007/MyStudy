### 解题思路
此题比较简单，思路就是按照规则，将输入的数字，按照规则，从大变小的思路，逐一将大整数变成小整数。

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string res;
        if (num >= 1000) {
            for(int i = 0; i < num / 1000; i++) {
                res += "M";
            }
            num = num % 1000;
        }
        if (num >= 900) {
            num = num - 900;
            res += "CM";
        }
        if (num >= 500) {
            num = num - 500;
            res += "D";
        }
        if (num >= 400) {
            num = num - 400;
            res += "CD";
        }
        if (num >= 100) {
            for(int i = 0; i < num / 100; i++) {
                res += "C";
            }
            num = num % 100;
        }
        if (num >= 90) {
            num = num - 90;
            res += "XC";
        }
        if (num >= 50) {
            num = num - 50;
            res += "L";
        }
        if (num >= 40) {
            num = num - 40;
            res += "XL";
        }
        if (num >= 10) {
            for(int i = 0; i < num / 10; i++) {
                res += "X";
            }
            num = num % 10;
        }
        if (num >= 9) {
            num = num - 9;
            res += "IX";
        }
        if (num >= 5) {
            num = num - 5;
            res += "V";
        }
        if (num >= 4) {
            num = num - 4;
            res += "IV";
        }
        for(int i = 0; i < num; i++) {
            res += "I";
        }
        return res;

    }
};
```