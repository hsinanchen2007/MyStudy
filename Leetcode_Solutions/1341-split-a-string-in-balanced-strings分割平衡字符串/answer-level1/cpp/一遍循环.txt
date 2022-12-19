```
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cntL = 0, cntR = 0;
        
        for(auto c : s)
        {
            if(c == 'R')
                cntR++;
            else
                cntL++;
            
            if(cntL == cntR)
            {
                res++;
                cntL = 0;
                cntR = 0;
            }
        }
        
        if(cntL > 0 && cntL == cntR)
            res++;
        
        return res;
    }
};
```