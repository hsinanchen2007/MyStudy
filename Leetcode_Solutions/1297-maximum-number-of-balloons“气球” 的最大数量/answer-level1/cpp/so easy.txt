```
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = 0;
        int b = 0, a = 0, l = 0, o = 0,n = 0;
        for(auto c : text)
        {
            if(c == 'b')
                b++;
            else if(c == 'a')
                a++;
            else if(c == 'l')
                l++;
            else if(c == 'o')
                o++;
            else if(c == 'n')
                n++;
        }
        
        while(b >= 1 && a >= 1 && l >= 2 && o >= 2 && n >= 1)
        {
            res++;
            
            b--;
            a--;
            l--;l--;
            o--;o--;
            n--;
        }
        
        return res;
    }
};
```