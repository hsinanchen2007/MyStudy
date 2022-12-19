```
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        // 让num1是短字符串
        if(num1.length() > num2.length()) swap(num1,num2);
        
        int len1 = num1.length(), len2 = num2.length(), i = 0;
        while(i<len2-len1)
        {
            num1 = "0" + num1;
            i++;
        }
        int a = 0, b = 0, idx = 1;
        while(idx <= len2)
        {
            a = num1[len2-idx]-'0' + num2[len2-idx]-'0' + b;
            b = a / 10;
            a %= 10;
            res = to_string(a) + res;
            idx++;
        }
        
        if(b != 0)
            res = to_string(b) + res;
        
        return res;
    }
};
```