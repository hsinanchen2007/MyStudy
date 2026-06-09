快速幂算法

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        int i=n;
        while(i){
            if(i&1)res*=x; 
            x*=x;          
            i>>=1;           
        }
        return n<0?1/res:res;
    }
};