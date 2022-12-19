```
class Solution {
public:
    int myAtoi(string str) {
        long long int res = 0;
        bool flag = 0;
        int i = 0;
        while (str[i] ==  ' ') {
            i++;
        }
        if (str[i] == '-') {
            flag = 1;
            i++;
        } else if (str[i] == '+') {
            i++;
        } 
        if (str[i] < '0' && str[i] > '9') {
            return 0;
        } else {
            while (str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + (int)(str[i] - '0');
                if (flag && -res < INT_MIN) {
                    return INT_MIN;
                } else if (!flag && res > INT_MAX) {
                    return INT_MAX;
                }
                i++;
            }
            if (flag) res = -res;
            return (int)res;
        }
    }
};
```
