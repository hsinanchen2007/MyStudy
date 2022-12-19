```
class Solution {
public:
    //int Calculate(string str, )
    int strToInt(string str) {
        // 整数运算的题目， 一定要对溢出情况进行判断
        // C++ climits库中有溢出的最值判断 INT_MAX etc
        int res = 0;
        // 确定是否为负数
        bool negative = false;
        // 找到第一个非空的字符
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '-') {
            negative = true;
        }
        // 收集符号信息
        if (str[i] == '+' || str[i] == '-') {
            i++;
        }
        while (i < str.size() && isdigit(str[i])) {
            // 最低位
            int num = negative == true ? ('0' - str[i]) : (str[i] - '0');
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7) ||
                res < INT_MIN / 10 || (res == INT_MIN / 10 && num < -8)) {
                return negative == true ? INT_MIN : INT_MAX;
            }
            res = res * 10 + num;
            i++;
        }
        return res;
    }
};
```
