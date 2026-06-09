二分查找法的套路就是：
1、设置一个起点a,一个终点b；
2、计算a和b的中点值tem;
然后不断判断tem是过大还是过小，
tem过大则让b变小，即b=tem;
tem过小则让a变大，即a=tem;
如此循环，直至b-a=1为终止条件，
因为在计算机中，此时tem恒=a,若此时不满足条件则进入死循环。
代码如下：
```
class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2) return n;
        long long a =0;
        long long b =n;
        long long k=a+b;
        
        while(b-a!=1){
        if( (1+k)*k/2==n ) return k;
        else if( (1+k)*k/2<n ) a = k;//列数过少
        else b = k;//列数过多
        k = (a+b)/2;
        }

        if( (1+b)*b/2>n ) return a;
        return b;
    }
};
```

