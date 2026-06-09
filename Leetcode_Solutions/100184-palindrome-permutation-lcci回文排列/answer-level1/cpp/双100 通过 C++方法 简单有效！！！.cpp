```
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> m;
        for(auto x:s)
        {
            m[x]++;
        }
        int i=0;
        for(auto x:m)
        {
            if(x.second%2==1)
            {
                i++;
            }
        }
        if(i>1) return false;
        if(i==1)
        {
            if(s.size()%2==1)
                return true;
            else
                return false;
        }
        return true;
    }
};
```
