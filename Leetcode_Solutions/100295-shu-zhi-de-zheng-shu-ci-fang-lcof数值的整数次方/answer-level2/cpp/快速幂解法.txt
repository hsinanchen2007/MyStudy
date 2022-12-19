![捕获.PNG](https://pic.leetcode-cn.com/53b02af87cc00aa50f7e60a9b170468eec83d2492385bc06f530ecc096e229e2-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        long b=n;
        if(b<0)
        {
            x=1/x;
            b=-b;
        }
        double res=1.0;
        while(b)
        {
            if((b&1)==1) res*=x;
             
            x*=x;
            b>>=1;

        }
        return res;

    }
};
```
