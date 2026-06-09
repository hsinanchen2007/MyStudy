```
class Solution {
public:
    double myPow(double x, int n) {
        if(doubleEqualTo0(x) && n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        
        double half = myPow(x, n/2);
        double rest = myPow(x, n%2);
        return half * half * rest;
    }
    
    bool doubleEqualTo0(double a){         // 注意这里！
        if(a>-0.0000001 && a < 0.0000001)  // 用 &&
            return true;
        return false;
    }
    
};
```
