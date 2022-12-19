```
class Solution {
public:
    string toHex(int num1) {
        if(num1 == 0) 
            return "0";
        string res = "";
        string hex[16] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        unsigned int num2 = num1;
        while(num2 != 0)
        {
            res = hex[num2 % 16] + res;  
            num2 /= 16;
        }
        return res;
    }
};
```