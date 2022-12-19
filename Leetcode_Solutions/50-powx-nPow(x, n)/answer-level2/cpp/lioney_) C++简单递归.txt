```
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double res = myPow(x, n/2);
        if(n % 2 == 0)
            return res * res;
        else if(n < 0)
            return res * res / x;
        else
            return res * res * x;
    }
};
```
