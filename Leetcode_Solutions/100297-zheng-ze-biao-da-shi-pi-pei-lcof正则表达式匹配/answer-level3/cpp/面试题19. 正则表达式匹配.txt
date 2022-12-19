```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        char * str = s.data();
        char * pat = p.data();
        if (*str =='\0' && *pat == '\0')
            return true;
        if (*str != '\0' && *pat == '\0')
            return false;

        if (*(pat+1) == '*') {
            if (*pat == *str || (*pat == '.' && *str != '\0'))
                // return isMatch(str, pat+2) || isMatch(str+1, pat) || isMatch(str+1, pat+2);  //重叠，超时
                return isMatch(str, pat+2) || isMatch(str+1, pat);
            else
                return isMatch(str, pat+2);
        }
        else if (*pat == *str || (*pat == '.' && *str != '\0'))
                return isMatch(str+1, pat+1);
        
        return false; 
    }       
        
};


```