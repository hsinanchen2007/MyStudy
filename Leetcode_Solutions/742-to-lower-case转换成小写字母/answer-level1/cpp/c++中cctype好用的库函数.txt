
```
class Solution {
public:
    string toLowerCase(string str) {
        string s="";
        for(int i=0;i<str.length();i++)
        {
            char c=tolower(str[i]);
            s+=c;
        }
        return s;
    }
};
```
