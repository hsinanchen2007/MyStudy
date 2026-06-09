### 解题思路



### 代码

```cpp

class Solution {
public:
    int myAtoi(const string &str) {
        enum STATE {
            s1,             //
            s2              //
        };
        STATE state = s1;
        int res = 0;
        bool sign = true;
        for (auto &ch: str) {
            if (state == s1) {
                if (isdigit(ch)) {
                    res = ch - '0';
                    state = s2;
                }else if (ch == '+'){
                    state = s2;
                }else if (ch == '-') {
                    sign = false;
                    state = s2;
                } else if (ch != ' ') {
                    break;
                }
            } else {
                if (isdigit(ch)) {
                    if (sign) {
                        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && ch - '0' > 7)) {
                            res = INT_MAX;
                            break;
                        }
                        res = res * 10 + (ch - '0');
                    } else {
                        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && ch - '0' > 8)) {
                            res = INT_MIN;
                            break;
                        }
                        res = res * 10 - (ch - '0');
                    }
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
```