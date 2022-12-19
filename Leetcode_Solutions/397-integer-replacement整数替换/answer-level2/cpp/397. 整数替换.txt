```
class Solution {
public:
    int integerReplacement(int n) {
        int res=0;
        while(n>3)
        {
            if(n%2)
            {
                n>>=1;
                if(n%2)++n;
                res+=2;
            }
            else
            {
                n>>=1;
                ++res;
            }
        }
        return res+n-1;
    }
};
```
