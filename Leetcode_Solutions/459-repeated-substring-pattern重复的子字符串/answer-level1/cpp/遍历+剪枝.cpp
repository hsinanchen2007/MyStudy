```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = 1;
        char c = s[0];
        while(n <= s.size()/2)
        {
            if(s.size() % n != 0 || s[n] != c)
            {
                n = s.find(c, n+1);
                if(n<0)
                {
                    return false;
                }
                continue;
            }
            if(checkSub(s, n++))
            {
                return true;
            }
        }
        return false;
    }
    bool checkSub(string s, int n)
    {
        int start = 0;
        while(start <= s.size() - n)
        {
            if(s.compare(start, n, s, 0, n) != 0)
                return false;
            start += n;
        }
        return true;
    }
};
```
