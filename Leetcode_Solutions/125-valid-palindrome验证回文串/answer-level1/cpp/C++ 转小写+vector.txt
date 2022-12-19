4 ms, 98.69%; 10.1 MB, 5.04%

```
class Solution {
public:
    bool isPalindrome(string s) {  
        vector<char> svec;
        
        for(int i = 0; i < s.length(); i++) s[i] = tolower(s[i]); // 全部转小写

        for(int i = 0; i < s.length(); i++)
            if(isalpha(s[i]) || isdigit(s[i]))
                svec.push_back(s[i]);
        
        for(int i = 0, j = svec.size()-1; i<j; i++, j--)
            if(svec[i]!=svec[j]) return false;
            else continue;

        return true;
    }
};
```
