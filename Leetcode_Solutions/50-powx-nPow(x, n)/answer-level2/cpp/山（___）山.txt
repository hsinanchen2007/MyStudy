### 解题思路
形参n你用int，实参你传个long

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if((x==1) ||(x== 0)) return x;
        double res=1;
        long long fuck=n;
        bool flag=false;
        if (fuck<0) 
        {
            fuck=-fuck;
            flag=true;
        }
       if(x==-1)
       {
           if(fuck%2) return -1;
           else return 1;
       } 
        while(fuck)
        {
            if(fuck&1) res*=x;
            fuck/=2;
            x*=x;
        }
        if(flag) return 1/res;
        else return res;
    }
};
```