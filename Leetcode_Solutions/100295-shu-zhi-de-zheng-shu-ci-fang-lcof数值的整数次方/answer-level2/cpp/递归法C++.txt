### 解题思路
注意：1、强制转换
2、递归：重复n/2直到n/2=1

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0&&n<=0) return 0.0;
        if(n==0) return 1.0;

        unsigned int m=(unsigned int)(n);
        if(n<0) m=-m;
        
        double res=pow(x,m);
        if(n<0) return 1/res;
        return res;
        }
        

        double pow(double x,int m)
        {
            if(m==0) return 1.0;
            if (m==1) return x;
            double res=pow(x,m/2);
           
           res=res*res;
           if(m&1) res=res*x;
            return res;
        }
        

    
};
```