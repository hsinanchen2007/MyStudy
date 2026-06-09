```
class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int sign = 1;
        int i = 0;
        // remove front spaces
        while (str[i] == ' ') ++i;
        if (str[i] >= '0' && str[i] <= '9') {
            res += 10 * res + str[i] - '0';
        } else if (str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '+') ? 1 : -1;
        } else {
            return 0;
        }
        // process following chars
        while (++i < str.size() && str[i] >= '0' && str[i] <= '9') {
            res = 10 * res + str[i] - '0';
            if (sign == 1 && res >= INT_MAX)
                return INT_MAX;
            if (sign == -1 && res * -1 <= INT_MIN)
                return INT_MIN;
        }
        return sign * res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8d73c01055698a7b14e1a05a565a3eb13641cd64f11066b05d29d4daeae556cd-image.png)
