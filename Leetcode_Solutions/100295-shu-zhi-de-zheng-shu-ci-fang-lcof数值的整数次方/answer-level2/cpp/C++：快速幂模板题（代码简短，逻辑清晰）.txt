**题解：**
快速幂模板题，比较简单，直接看代码即可，含有部分注解。

**代码如下：**
```cpp
class Solution {
public:
    //题解：快速幂
    double myPow(double x, int n) {
        double res=1.0;
        int i=n;
        while(i){
            if(i&1)res*=x;  //i的低位存在，res*x
            x*=x;           //x扩大为它的平方，因为二进制每位的差距是平方关系
            i/=2;           //i向0靠近
        }
        return n<0?1/res:res;
    }
};
```
