```
class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        unordered_map<char,int>mp;
        for(int i=1;i<=26;i++){
            mp['A'+i-1]=i;
        }
        int n=s.size()-1;
        for(int i=n;i>=0;i--){
            result+=mp[s[i]]*pow(26,n-i);
        }
        return result;
    }
};
```
