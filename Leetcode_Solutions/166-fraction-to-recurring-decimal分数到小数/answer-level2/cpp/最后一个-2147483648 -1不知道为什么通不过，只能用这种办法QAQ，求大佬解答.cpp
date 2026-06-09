### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       bool flag1 = false,flag3 = false; //判断分母,分子是否为负数
       long long num = static_cast<long long>(numerator);
       long long den = static_cast<long long>(denominator);
       if (den == -1) return to_string(2147483648);
       if (den < 0) {
           den = abs(den);
           flag1 = true;
       }
       if (num < 0) {
           num = abs(num);
           flag3 = true;
       }
       int part1 = num / den; //保存整数部分
       int64_t reminder = num % den; //开始循环的第一个余数
       reminder = abs(reminder);
       if (reminder == 0) return to_string(part1);
       
       vector<int> part2; //保存小数部分
       vector<int> remains; //保存每次循环得到的新余数
       bool flag2 = false; //判断是否为循环小数
       int pos = 0; //保存小数开始循环的位置，如0.1(6)
       while (find(remains.begin(),remains.end(),reminder) == remains.end()) { 
           //若出现了之前出现过的余数，说明小数开始循环;若没出现,继续迭代
           int64_t newnum = reminder * 10;
           part2.push_back(newnum / den);
           remains.push_back(reminder);
           reminder = newnum % den;
           if (reminder == 0) {  //如果能除的尽，则跳出循环
               flag2 = true;
               break;
            } 
        }
        for (int i = 0 ; i < remains.size(); ++i) {
            if (remains[i] == reminder) {
                pos = i;
                break;
            }
        }
        //输出字符串
        string res;
        if (flag1) {
            if (!flag3) res += "-";
        }else {
            if (flag3) res += "-";
        }
        res += to_string(part1)+".";
        if (flag2) {
            for (auto a:part2) {
                res += to_string(a);
            }
        }else {
            for (int i = 0 ; i < pos ; ++i) {
                res += to_string(part2[i]);
            }
            res += "(";
            for (int i = pos ; i < part2.size() ; ++i) {
                res += to_string(part2[i]);
            }
            res += ")";
        }

        return res;
    }
};
```