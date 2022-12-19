```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())return s;
        int li=0;
        int lj=0;
        for(int i=0;i<s.size();++i){//奇回文
            int j=0;
            while(i-j>=0&&i+j<s.size()){
                if(s[i-j]!=s[i+j])break;
                if(2*j>lj-li){
                    lj=i+j;
                    li=i-j;
                }
                ++j;
            }
        }
        for(int i=0;i<s.size()-1;++i){//偶回文
            int j=0;
            while(i-j>=0&&i+1+j<s.size()){
                if(s[i-j]!=s[i+1+j])break;
                if(2*j+1>lj-li){
                    lj=i+1+j;
                    li=i-j;
                }
                ++j;
            }
        }
        return s.substr(li,lj-li+1);
    }
};
```
