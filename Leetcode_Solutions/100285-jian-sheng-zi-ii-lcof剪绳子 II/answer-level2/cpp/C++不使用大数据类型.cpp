```
class Solution {
public:
    int cuttingRope(int n) {
        if(n<4)
            return n==2? 1:2;
        
        int res=1;
        while(n>4){
            if(res>=333333335){
                int left = res/333333335;
                res %= 333333335;
                res = 3*res - 2*left;
            }
            else
                res *= 3;
            n -= 3;
        }

        if(n==1)
            return res;
        else{
            int lim = 1000000007/n;
            int flag = 1000000007 - n*lim;
            if(res >= lim){
                int mul = res/lim;
                res %= lim;
                res = n*res - mul*flag;
                return res;
            }
            return n*res;
        }
    }
};
```
