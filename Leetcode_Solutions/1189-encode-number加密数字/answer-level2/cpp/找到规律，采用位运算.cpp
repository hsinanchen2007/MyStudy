```
class Solution {
public:
    string encode(int num) {
        string s="";
        int n=num+1;
        while(n){
            s+=to_string(n&1);
            n>>=1;
        }
        //此时s为正确结果的倒置
        string ans="";
        for(int i=s.length()-2;i>=0;i--)
            ans+=s[i];
        return ans;
    }
};
```
