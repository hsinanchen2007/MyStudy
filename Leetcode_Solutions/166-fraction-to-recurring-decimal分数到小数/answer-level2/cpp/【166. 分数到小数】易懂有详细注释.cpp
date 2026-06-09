### 思路


### 代码

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = (numerator > 0) ^ (denominator > 0) ? -1 : 1;
        long num = labs(numerator), den = labs(denominator);
        long out = num / den, rem = num % den;
        unordered_map<long, long> ump;//用于保存小数部分，便于判断是否有重复出现
        string res = to_string(out);
        //1. 初始判断是否需要加负号
        if (sign == -1 && (out > 0 || rem > 0)) res = "-" + res;
        //2. 如果整除没有小数部分，则直接返回
        if (rem == 0) return res;
        //3. 有小数部分
        res += ".";
        string s;
        int pos = 0;
        while (rem != 0) {
            //出现重复，则在重复位置前加入左括号并在最后位置加入右括号，最后和整数部分相加返回
            if (ump.find(rem) != ump.end()) {
                s.insert(ump[rem], "(");
                s += ")";
                return res + s;
            }
            ump[rem] = pos;
            ++pos;
            s += to_string((rem * 10) / den);//余数乘10再除以分母得到下一位小数
            rem = (rem * 10) % den;//继续求出下一位余数
        }
        return res + s;
    }
};
```