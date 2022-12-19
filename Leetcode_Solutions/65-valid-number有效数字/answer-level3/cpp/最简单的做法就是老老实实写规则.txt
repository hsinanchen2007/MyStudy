```
class Solution {
public:
    
    bool isAllNumber(string s)
    {
        for(auto c : s)
        {
            if(c < '0' || c > '9')
                return false;
        }
        return true;
    }
    
    // 判断是否是合法的十进制数字
    bool isValidNumber(string s)
    {
        if(s.length() > 1 && s[0] == 0)
            return false;
            
        return true;
    }
    
    string trim(string s)
    {
        while(s[0] == ' ')
        {
            s = s.substr(1);
        }
        
        while(s[s.length()-1] == ' ')
        {
            s = s.substr(0,s.length()-1);
        }
        return s;
    }
    
    bool isNumber(string s) 
    {
        s = trim(s);
        
        if(s.length() <= 0) return false;
        
        // 剩下的字符串分成两种情况：全数字和非全数字
        if(isAllNumber(s))
        {
            return isValidNumber(s);
        }
        else
        {
            // 非全数字分成4种情况：1.只含字母e 2.同时含字母e和小数点 3.只含小数点 4.其他
            
            int idx_e = s.find('e');
   
            if(idx_e != s.npos)
            {
                string s1 = s.substr(0,idx_e), s2 = s.substr(idx_e+1);
                // e的左右两边都都可以带正负号，但是去掉正负号後都不能为空，且右边只能是全数字
                if(s1[0] == '-' || s1[0] == '+') s1 = s1.substr(1);   
                if(s2[0] == '-' || s2[0] == '+') s2 = s2.substr(1);
                if(s1.length() == 0 || s2.length() == 0 || isAllNumber(s2) == false) return false;
                
                // e的左边可以含有小数点
                int idx_p = s1.find('.');
                if(idx_p != s1.npos)
                {
                    string s11 = s1.substr(0,idx_p), s12 = s1.substr(idx_p+1);
                    if(s11.length() == 0 && s12.length() == 0) return false;
                    if(s11.length() > 0 && isAllNumber(s11) == false) return false;
                    if(s12.length() > 0 && isAllNumber(s12) == false) return false;
                }
                else
                {
                    if(isAllNumber(s1) == false || isValidNumber(s1) == false) return false;
                }
            }
            else
            {
                if(s[0] == '-' || s[0] == '+') s = s.substr(1);   
                // 不包含e，但是包含小数点
                int idx_p = s.find('.');
                if(idx_p != s.npos)
                {
                    string s1 = s.substr(0,idx_p), s2 = s.substr(idx_p+1);
                    if(s1.length() == 0 && s2.length() == 0) return false;
                    if(s1.length() > 0 && isAllNumber(s1) == false) return false;
                    if(s2.length() > 0 && isAllNumber(s2) == false) return false;
                }
                else
                {
                    // 不包含e，且不包含小数点
                    if(isAllNumber(s) == false) return false;
                }
            }
               
        }
        
        return true;
    }
};
```