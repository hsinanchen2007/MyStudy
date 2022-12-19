### 解题思路
此题利用位运算再相乘，将负数转化为正数来计算，要注意x等于0和1时始终是0和1，此外要注意当n等于INT_MIN时的越界问题。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0||x==1)
        return x;
        int n1=n;       //保存x与n的值
        double x1=x;
        if(n==INT_MIN){  //处理越界问题
            n++;
        }
        if(n<0){         //处理负数情况
            x=1/x;
            n*=-1; 
        }
        vector<double> a;    
        vector<bool> b;
        while(n>0){
            a.push_back(x);
            b.push_back(n&1);
            x*=x;
            n=n>>1;
        }
        double ans=1;
        for(int i=0;i<b.size();i++){
            if(b[i])
            ans*=a[i];
        }
        if(n1==INT_MIN){
            return ans/x1;
        }
        return ans;
    }
};
```