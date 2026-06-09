
```cpp
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";    
        string res;
        bool flag = false;
        if (num < 0) {
            flag = true;
            num = abs(num);
        }        
        while (num > 0) {
            if (num < 7) {
                res = to_string(num) + res;
                break;
            }            
            res = to_string(num % 7) + res;
            num = num / 7;            
        }
        if (flag) res = "-" + res;
        return res;
    }
};
```