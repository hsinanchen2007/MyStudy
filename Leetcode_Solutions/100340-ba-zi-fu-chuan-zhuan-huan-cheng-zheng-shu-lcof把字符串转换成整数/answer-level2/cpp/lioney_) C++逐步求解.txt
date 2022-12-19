```
class Solution {
public:
    int strToInt(string str) {
        int l = 0, sign = 1;
        long res = 0;
        // 去掉前面的空格
        while(str[l] == ' ' && l<str.size()) l++;
        if(str[l] == '+') l++;
        else if(str[l] == '-') {
            sign = -1;
            l++;
        }
        while(l < str.size()) {
            if(str[l] >= '0' && str[l] <= '9') {
                res = res * 10 + (str[l] - '0');
                if(res * sign > INT_MAX) return INT_MAX;
                else if(res * sign < INT_MIN) return INT_MIN;
                l++;
            }
            // 不是数字即退出
            else break;
        }
        res *= sign;
        return res;
    }
};
```
