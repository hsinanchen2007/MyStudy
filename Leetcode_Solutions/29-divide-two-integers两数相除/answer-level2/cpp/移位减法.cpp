```
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 0;
        unsigned int ret = 0;
        unsigned long d1,d2;
        if(dividend < 0)
        {
            d1 = (unsigned int)~dividend + 1;
            sign = 1;
        }
        else
        {
            d1 = dividend;
        }
        if(divisor < 0)
        {
            d2 = (unsigned int)~divisor + 1;
            sign ^= 1;
        }
        else
        {
            d2 = divisor;
        }
        int multi = 31;

        while(d1 >= d2)
        {
            while((d2<<multi) > d1)
            {
                multi--;
            }
            ret += (1<<multi);
            d1 -= (d2<<multi);
        }
        if(sign)
        {
            return ~(ret-1);
        }
        else
        {
            if(ret >= (1<<31))
                return (1<<31)-1;
            else
                return ret;
        }
    }
};
```
