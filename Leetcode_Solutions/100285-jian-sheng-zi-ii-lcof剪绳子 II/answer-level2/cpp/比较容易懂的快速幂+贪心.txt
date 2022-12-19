举一个例子，数字 8 = 3 + 3 + 2 = 4 + 4，我们这里肯定是取 3, 3, 2
1. 因为4的个数为双数(8的倍数)时，将其拆分成 3*b+2 的形式会有更大的收益；
2. 但是！在4只剩一个的时候，将其拆成 2*2 的形式会有更大的收益。

所以应该先让3填充n,即 remain = n - 3b, b++的过程。再来看最后有没有可能剩下一个4，因为设置条件中的 n - 3b有可能等于4，3，2，1，0。其实这个时候不论最后剩下的是什么，直接乘上前面的结果就完事了昂。

```
class Solution {
public:
    long long pow(long long  a,long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b&1) ans = (ans * a)%1000000007;
            a = (a * a)%1000000007;
            b>>=1;

        }
        return ans;
    }
    int cuttingRope(int n) {
        long long ans = 1;
        int b = 0;
        int remain;
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;
        while(n-3*b>4) //用3尽力填充n， n-3*b 表示填充完之后还剩下的数,也就是上面说到的可能为0,1,2,3,4的值
            b++;
        return (pow(3,b)*(n-3*b))%1000000007;
        
    }
};
```
