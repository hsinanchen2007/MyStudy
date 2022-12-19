### 解题思路
就在基础上添加一个指数为负的情况即可（也就直接把x换成1/x，指数变成正就可以了）

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long num=n;
        int cur=0;
        double ans=1.00;
        if(num<0)
        {
            x=1/x;
            num*=-1;
        }
        while(num!=0)
        {
            cur=num%2;
            num/=2;
            if(cur==1)
                ans*=x;
            x*=x;
        }
        return ans;
    }
};
```