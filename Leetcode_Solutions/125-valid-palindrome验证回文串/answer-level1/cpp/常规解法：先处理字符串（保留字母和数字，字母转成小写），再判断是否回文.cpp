```
class Solution {
public:

    string func(string s)
    {
        string res = "";
        for(auto c : s)
        {
            if(c >= 'A' && c <= 'Z')
            {
                res += (c + 32);
            }
            else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            {
                res += c;
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        string s2 = func(s);
        int i=0,j=s2.length()-1;
        while(i<j)
        {
            if(s2[i++] != s2[j--])
                return false;
        }
        return true;
    }
};
```