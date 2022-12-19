### 解题思路
参考官方题解

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        size_t i = 0;
        bool neg = false;
        while (str[i] == ' ') {
            ++i;
        }
        if (str[i] == '-' || str[i] == '+') {
            neg = (str[i] - '+');
            ++i;
        }
        
        while (str[i] >= '0' && str[i] <='9') {
            if (result > INT_MAX / 10 || ((result == INT_MAX / 10) && (str[i] - '0') > INT_MAX % 10)) {
                return neg ? INT_MIN : INT_MAX;
            }

            result = result * 10 + (str[i] - '0');
            ++i;
        }
        return neg ? -result : result;    
    }
};
```