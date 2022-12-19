```
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty() || num2.empty()) return !num1.empty() ?num1:num2;
        string s1;
        const int m=num1.size(),n=num2.size();
        int carry=0;
        for(int i=0; i<m||i<n ;++i)
        {
            int a= i<m ?(num1[m-1-i]-'0'):0;
            int b= i<n ?(num2[n-1-i]-'0'):0;
            a=a+b+carry;
            carry=a/10;
            s1=to_string(a%10)+s1;
        }
        if(carry==1)
            s1=to_string(1)+s1;
        return s1;
    }
};
```
