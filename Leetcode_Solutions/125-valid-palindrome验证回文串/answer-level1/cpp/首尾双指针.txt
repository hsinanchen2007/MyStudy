从前遍历找到i使得s[i]是字母或数字；
从后遍历找到j使得s[j]是字母或数字；
忽略大小写判断s[i]==s[j]。
```
class Solution {
public:
    bool isPalindrome(string &s) {
        for(int i=0, j=s.length()-1; i<j; ++i, --j){
            for(; i<j && !isalnum(s[i]); ++i);
            for(; i<j && !isalnum(s[j]); --j);
            if(tolower(s[i])!=tolower(s[j])) return false;
        }
        return true;
    }
};
```
