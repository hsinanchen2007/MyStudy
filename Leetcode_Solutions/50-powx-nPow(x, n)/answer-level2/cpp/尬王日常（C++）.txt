### 解题思路
long long 卡半天
### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double res = 1 ;double base = x;int flag = 0;
        if(N<0){base = 1/base;flag = 1;N*=-1;}
        while(N!=0)
        {
            if(N&1!=0)
            {
                res*=base;
            }
            N>>=1;
            base*=base;
        }
        
        return res;
    }
};
