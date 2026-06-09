### 解题思路
牛顿迭代法求平方根
求解时要主要变量类型为double;
相除时要➗（2.0）
### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        //牛顿迭代法求平方根
        if(x<2)return x;
        double Xn=x;
        double lastvalue=Xn/2.0+x/2.0/Xn;
        while(abs(lastvalue-Xn)>=1){
            Xn=lastvalue;
            lastvalue=Xn/2.0+x/2.0/Xn;
        }
        return (int)lastvalue;
        
    }
};
```