```
class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decodeString(s,i);
    }
    string decodeString(string &s,int &i) {
        string res;
        int num=0;
        for(;i<s.size();++i){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')res+=s[i];
            else if(s[i]>='0'&&s[i]<='9')num=num*10+(s[i]-'0');
            else if(s[i]=='['){
                ++i;
                auto s2=decodeString(s,i);
                for(;num>0;--num){
                    res+=s2;
                }
            }else if(s[i]==']'){
                return res;
            }
        }
        return res;
    }
};
```
