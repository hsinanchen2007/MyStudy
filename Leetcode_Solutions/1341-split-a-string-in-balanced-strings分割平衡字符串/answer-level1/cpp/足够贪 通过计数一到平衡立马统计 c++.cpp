```
class Solution {
public:
    int balancedStringSplit(string s) {
        int i,j;
        int cr=0,cl=0;
        int ans=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='L') cl++;
            if(s[i]=='R') cr++;
            if(cl==cr){
                ans++;
                cl=0;
                cr=0;
            }
        }
        return ans;
    }
};
```
