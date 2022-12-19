```
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        string result(n1 + n2, '0');
        string tmp(n1 + n2, '0');
        for (int i = n2 - 1; i >= 0; --i){
            int carry = 0;
            for (int j = n1 - 1; j >= 0; --j){
                tmp[i+j+1] = ((num2[i]-'0')*(num1[j]-'0')+carry)%10 + '0';
                carry = ((num2[i]-'0')*(num1[j]-'0')+carry)/10;
            }
            if (carry) tmp[i] = carry + '0';
            carry = 0;
            char tmpChar;
            for (int k = n1 + n2 - 1; k >= 0; --k){
                tmpChar = result[k];
                result[k] = ((result[k]-'0') + (tmp[k]-'0') + carry)%10 + '0';
                carry = (tmpChar-'0' + tmp[k]-'0' + carry) / 10;
                tmp[k] = '0';
            }
        }
        string final;
        for (int i = 0; i < n1 + n2; ++i){
            if (result[i]=='0' && final.length()==0) continue;
            final += result[i];
        }
        if (final.length()==0) final += '0';
        return final;
    }
};
```
