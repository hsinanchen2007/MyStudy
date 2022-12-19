执行结果：通过
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了96.48%的用户

```
class Solution {
public:
    string intToRoman(int num) {
        string result;
        // 先对M进行计算
        int valM = num / 1000;
        for (int i = 0; i < valM; i++) {
            result += "M";
        }
        num -= valM * 1000;
        
        // 计算百位数
        int valC = num / 100;
        if (valC == 9) {
            result += "CM";
        } else if (valC == 4) {
            result += "CD";
        } else if (valC >= 5) {
            result += "D";
            for (int i = 0; i < valC - 5; i++) {
                result += "C";
            }
        } else {
            for (int i = 0; i < valC; i++) {
                result += "C";
            }
        }
        num -= valC * 100;
        
        //计算十位数
        int valX = num / 10;
        if (valX == 9) {
            result += "XC";
        } else if (valX == 4) {
            result += "XL";
        } else if (valX >= 5) {
            result += "L";
            for (int i = 0; i < valX - 5; i++) {
                result += "X";
            }
        } else {
            for (int i = 0; i < valX; i++) {
                result += "X";
            }
        }
        num -= valX * 10;
        
        //计算个位数
        int valI = num;
        if (valI == 9) {
            result += "IX";
        } else if (valI == 4) {
            result += "IV";
        } else if (valI >= 5) {
            result += "V";
            for (int i = 0; i < valI - 5; i++) {
                result += "I";
            }
        } else {
            for (int i = 0; i < valI; i++) {
                result += "I";
            }
        }
        
        return result;
    }
};
```
