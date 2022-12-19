```
class Solution {
public:
    int mySqrt(int x) {
        double r=1.0;
        for(; abs(r*r-x)>1e-1; r=(r+x/r)/2);
        return r;
    }
};
```