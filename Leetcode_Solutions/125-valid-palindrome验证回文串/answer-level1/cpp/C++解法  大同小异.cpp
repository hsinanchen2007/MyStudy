```
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1)
            return true;
        int p=0,h=s.size()-1;
        while(p<h){
            while(p<h&&!isalpha(s[p])&&!isdigit(s[p]))
                p++;
            while(p<h&&!isalpha(s[h])&&!isdigit(s[h]))
                h--;
            if(tolower(s[p])!=tolower(s[h]))
                return false;
                p++,h--;
        }
        return true;
    }
};
```
