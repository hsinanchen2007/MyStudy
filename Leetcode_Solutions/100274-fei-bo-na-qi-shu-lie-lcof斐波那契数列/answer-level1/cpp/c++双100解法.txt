因为有规划方程，为节省空间可以只用两个值来保存结果，用一个bool量来保存反转状态代码如下
```
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        bool rever=true;
        int fir=0,sec=1;
        for(int i=2;i<=n;i++){
            if(rever)fir=(fir+sec)%1000000007;
            else sec=(sec+fir)%1000000007;
            rever=1-rever;
        }
        if(rever)return sec;
        else return fir;
    }
};
```
