```
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;--i){
            string num(num2.size()+num1.size()-i,'0');
            int carry=0;
            int k=num.size()-1-(num1.size()-i-1);
            for(int j=num2.size()-1;j>=0;--j,--k){
                int sum=(num1[i]-'0')*(num2[j]-'0')+carry;
                num[k]='0'+sum%10;
                carry=sum/10;
            }
            if(carry>0)num[k]='0'+carry;
            plus(res,num);
        }
        int i=0;
        for(;i<res.size();++i){
            if(res[i]!='0')break;
        }
        if(i==res.size())return "0";
        return res.substr(i);
    }
    void plus(string &res,string &num){
        int carry=0;
        int i=res.size()-1;
        for(int j=num.size()-1;j>=0;--i,--j){
            int sum=res[i]-'0'+num[j]-'0'+carry;
            res[i]='0'+sum%10;
            carry=sum/10;  
        }
        if(carry>0)res[i]='0'+carry;
    }
};
```
