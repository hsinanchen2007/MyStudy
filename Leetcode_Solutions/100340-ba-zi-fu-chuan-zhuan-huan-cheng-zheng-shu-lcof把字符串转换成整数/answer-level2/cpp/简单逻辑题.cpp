```
class Solution {
public:
    int strToInt(string str) {
        int i=0, n = str.size();
        long long int res = 0;
        // 1. 丢弃开始的空格
        for(; i<n && isspace(str[i]); i++);

        // 2. 判断加减号
        int sign = 1;
        if(str[i] == '+' || str[i] == '-') {
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }
        // 3. 遍历
        for(; i<n && isdigit(str[i]); i++) {
            int digit = str[i] - '0';
            res = 10*res + digit;
            if(sign*res > INT_MAX) {
                return INT_MAX;
            }
            if(sign*res < INT_MIN) {
                return INT_MIN;
            }
        }
        return res*sign;
    }
};
```