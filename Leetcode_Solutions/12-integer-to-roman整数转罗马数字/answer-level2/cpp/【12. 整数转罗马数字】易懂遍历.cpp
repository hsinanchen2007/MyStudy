### 思路

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string res;
        while (num > 0) {
            int n;
            if (num >= 1000) {
                n = num / 1000;
                res += string(n, 'M');
                num %= 1000;
            } else if (num >= 900) {
                res += "CM";
                num -= 900;
            } else if (num >= 500) {
                res += 'D';
                num -= 500;
            } else if (num >= 400) {
                res += "CD";
                num -= 400;
            } else if (num >= 100) {
                n = num / 100;
                res += string(n, 'C');
                num %= 100;
            } else if (num >= 90) {
                res += "XC";
                num -= 90;
            } else if (num >= 50) {
                res += 'L';
                num -= 50;
            } else if (num >= 40) {
                res += "XL";
                num -= 40;
            } else if (num >= 10) {
                n = num / 10;
                res += string(n, 'X');
                num %= 10;
            } else if (num == 9) {
                res += "IX";
                num -= 9;
            } else if (num >= 5) {
                res += 'V';
                num -= 5;
            } else if (num == 4) {
                res += "IV";
                num -= 4;
            } else if (num >= 1) {
                res += string(num, 'I');
                num -= num;
            }
        }
        return res;
    }
};
```

### 简化
```c++
class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                num -= values[i];
                res += str[i];
            }
        }
        return res;
    }
};
```
