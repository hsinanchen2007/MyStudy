不写注释应该看得懂吧
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry =0,i=num1.size()-1,j = num2.size()-1;
        while(i>=0||j>=0||carry){
            if(i>=0) carry+=num1[i--]-'0';
            if(j>=0) carry+=num2[j--]-'0';
            res = char('0'+carry%10) +res;
            carry/=10;
        }
        return res;
    }  
};
```