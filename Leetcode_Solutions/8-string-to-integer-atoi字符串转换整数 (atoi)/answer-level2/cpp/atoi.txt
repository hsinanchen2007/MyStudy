```
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int prefix = 0;
        int i = 0;

        while (i < str.length() && str[i] == ' ') {
            ++i;
        }

        while (i < str.length()) {
            if (str[i] == '-' || str[i] == '+') {
                if (prefix != 0) {
                    return prefix * res;
                }

                prefix = str[i] == '-' ? -1 : 1;
                ++i;
                continue;
            } 

            if (prefix == 0) {
                prefix = 1;
            }

            if (str[i] < '0' || str[i] > '9') {
                return prefix * res;
            }

            res = res * 10 + str[i++] - '0';

            if (res * prefix <= INT_MIN) {
                return INT_MIN;
            } else if (res * prefix >= INT_MAX) {
                return INT_MAX;
            }
        }

        return prefix * res;
    }
};
```
