### 解题思路
此处撰写解题思路
溢出处理 或者直接换long
### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n==-2147483648) return 1/(myPow(x,2147483647)*x);
        if(n<0) return 1/(myPow(x,-n));
        if(n==0) return 1;
        if(n==1) return x;
        if(n==2) return x*x;
        if(n%2!=0) return myPow(x,n-1)*x;

        double aaa=myPow(x,n/2);
        return aaa*aaa;
    }
};
```