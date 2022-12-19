&emsp;&emsp;弱鸡贴一下自己找到的方法。设$g(n)=f(2n)$,则$g(n)=g(0)*g(n-1)+g(1)*g(n-2)+...+g(n-1)*g(0)$，这正是卡特兰数的递推式，所以$g(n)=f(2n)=\frac{C(2n,n)}{n+1}$。鉴于题目中n的范围是1000，不能直接求卡特兰数mod p的值，要用Lucas定理来求大的组合数。
&emsp;&emsp;Lucas定理表达式:`Lucas(n,m,p)=C(n%p,m%p)*Lucas(n/p,m/p,p)`。
&emsp;&emsp;关于定理更详细的解释可以参考:https://blog.csdn.net/zuzhiang/article/details/77966726和https://blog.csdn.net/u014492306/article/details/41318605.
```c++
typedef long long LL;
class Solution {
public:
    //快速幂
    LL pow(LL n, LL m, LL p){
        LL res=1, a=n;
        while(m){
            if(m&1) res=(a*res)%p;
            a=(a*a)%p;
            m>>=1;
        }
        return res;
    }
    
    LL com(LL n, LL m, LL p){
        LL a=1, b=1;
        if(m > n) return 0;
        while(m){
            a=(a*n--)%p;
            b=(b*m--)%p;
        }
        return a*pow(b,p-2,p)%p;
    }
    
    LL Lucas(int n, int m, int p){
        if(m==0) return 1;
        return com(n%p, m%p, p)*Lucas(n/p, m/p, p);
    }
    int numberOfWays(int n) {
        n /=2;
        int p=1e9+7;
        return (Lucas(2*n,n,p)-Lucas(2*n,n-1,p)+p)%p;
    }
};
```

