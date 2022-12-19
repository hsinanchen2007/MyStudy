### 解题思路
if-else 暴力***
### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        auto pos = s.find_first_not_of(" ");
        if(pos == string::npos)
            return false;
        
        s = s.substr(pos);
        pos = s.find_last_not_of(" ");
        s = s.substr(0, pos+1);
        pos = s.find_first_not_of("0123456789e+-.");
        if(pos != string::npos)
            return false;

        pos = s.find_first_of("e");
        if(pos != s.find_last_of("e"))
            return false;
 
        if(pos != string::npos)
            return helper(s.substr(0, pos), false) && helper(s.substr(pos+1, s.size()-pos-1), true);
        else
            return helper(s, false);
    }

    bool helper(string s, bool flag)
    {
        if(s.empty())
            return false;

        auto pos = s.find('.');
        if(flag && pos != string::npos)
            return false;
        if(pos != s.find_last_of("."))
            return false;
        if( pos != string::npos && s.size() == 1)
            return false;

        pos = s.find_last_of("+-");
        if(pos != string::npos && (pos != 0 || s.find_first_of("0123456789") == string::npos))
            return false;

        return s.find_first_not_of("0123456789.+-") == string::npos; 
    }
};
```