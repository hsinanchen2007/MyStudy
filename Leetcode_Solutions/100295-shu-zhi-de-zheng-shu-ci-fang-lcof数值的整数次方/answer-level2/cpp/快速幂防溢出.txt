```C++
class Solution {
public:
    double myPow(double x, int n) {
        if (abs(x)<1e-6) return 0;
        if (abs(x-1)<1e-6) return 1;
        if (abs(x+1)<1e-6) return n%2?-1:1;
        double ans = 1;
        double base = x;
        int exp = 0;
        if (n==INT_MIN) exp=abs(n+1);
        else exp = abs(n);
        while (exp > 0) {
            if (exp & 1) {
                ans*=base;
                exp--;
            }
            else {
                base *= base;
                exp>>=1;
            }
        }
        if (n==INT_MIN) ans *= x;
        if (n<0) ans = 1/ans;
        return ans;
    }
};
```
复杂度O(logn)
