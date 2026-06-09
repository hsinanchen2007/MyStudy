```
class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        long ln = n;
        if(ln == 0)
        {
            return 1.0;
        }
        else if(ln<0)
        {
            x = 1/x;
            ln = -ln;
        }
        while(ln>0)
        {
            if((ln & 1) == 1)
            {
                ret *= x;
            }
            x *= x;
            ln >>= 1;
        }
        return ret;
    }
};
```
