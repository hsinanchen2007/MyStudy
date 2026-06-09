```
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int res = 1;
        int l = 1, r = x;
        while( res != x / res)
        {
            res = l + (r - l) /2 ;
            if(res > (x/res))
                r = res - 1;
            else if (res < (x/res))
                l = res + 1;
            if((res + 1) > x/(res+ 1) && res < x/res)
                break;
        }
        return res;
    }
};
```
