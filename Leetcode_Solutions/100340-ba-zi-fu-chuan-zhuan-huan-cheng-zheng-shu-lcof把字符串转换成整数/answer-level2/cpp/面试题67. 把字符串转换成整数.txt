```cpp

class Solution {
public:
    int strToInt(string str) {
        int begin = 0;
        long long res = 0;
        int sign = 1;
        while (begin < str.size() && str[begin] == ' ')  begin ++;
        if (str[begin] == '-') {
            sign = -1; 
            begin ++;
        }
        else if (str[begin] == '+')
            begin ++;
        
        while (begin < str.size() && str[begin] >= '0' && str[begin] <= '9') {
            // if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[begin] > '7')) 
            //     return sign == 1 ? INT_MAX : INT_MIN; //将 res设为 int
            
            res = res * 10 + (str[begin] - '0');
            if (res * sign > INT_MAX) return INT_MAX;  //或者将 res设为 long long
            else if (res * sign < INT_MIN) return INT_MIN;
            begin ++;
        }
        return res * sign;
    }
};

      
```