```
class Solution {
public:
    string convertToBase7(int num) {
        
        if(num == 0) return "0";
        
        string res = "";
        bool negtive = false;
        
        if(num < 0)
        {
            negtive = true;
            num = 0 - num;
        }
        
        while(num > 0)
        {
            res = to_string(num % 7) + res;
            num /= 7;
        }

        return negtive ? "-" + res : res;
    }
};
```