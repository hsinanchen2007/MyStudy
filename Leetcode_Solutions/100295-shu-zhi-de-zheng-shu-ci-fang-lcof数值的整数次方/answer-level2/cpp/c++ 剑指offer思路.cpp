/*根据剑指offer公式来的*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        double res = myPow(x,n >> 1);
        res *= res;
        if (n & 1) res *= x;
        return res;   
    }
};