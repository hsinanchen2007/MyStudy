class Solution {
public:
    bool ischoushu(int n){
        while(n%2==0){
            n/=2;
        }
        while(n%3==0)
        {
            n/=3;
        }
        while(n%5==0)
        {
            n/=5;
        }
        return n==1;
    }
    int nthUglyNumber(int n) {
        int dp=1;
        while(--n){
            while(1){
               if(ischoushu(++dp))
                  break;
            }
        }
        return dp;
    }
};