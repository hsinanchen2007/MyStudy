这一题和上一题一样的，但是数据范围扩大了很多，数据范围大了会直接导致递归不能使用了。因为取余后 2000000014 会小于 1000000020，dp数组求解的时候会受到影响。
所以~ 还是使用上题提到的贪心方法。
另外，pow函数用不了了，必须要自己写。
我是真的不容易，裹了三层取余才不会溢出。。。
这样也能打败双百。
方法1：递归
```
class Solution {
public:
    int fun(int n){
        if(n>4){
            int tmp = fun(n-3);
            return ((tmp%1000000007+tmp)%1000000007+tmp)%1000000007;
        }
        return n;
    }
    int cuttingRope(int n) {
        if(n==2||n==3)
            return n-1;
        return fun(n);
    }
};
```

方法2:快速幂
快速幂如果不懂的话，可以去做第50题，使用这个就是为了方便在求幂的时候取余
```
while(n > 0)
{
		if(n % 2 > 0) ans *= x;
		n /= 2;
		x = x * x;
}
```
这个怎么理解呢，比如说2的100次方，它就等于4的50次方，也等于16的25次方，25是奇数，不能进一步分，我们就把答案乘上一个16，然后把它变成16的24次方继续分。。。
这个数据的边界真的是无趣，所有能加取余的地方都加一个。
```
class Solution {
public:
    long long mypow(int x){//pow(n,x)
        if(x==0)
            return 1; 
        if(x%2)
            return 3*(mypow(x-1))%1000000007;
        else
        {
            long long half = mypow(x/2);
            return (half%1000000007*half%1000000007)%1000000007;    
        }
    }
    int cuttingRope(int n) {
        if(n<4)
            return n-1;
        int a = n%3,b = n/3;
        if(a==1)
            return mypow(b-1)*(long long)4%1000000007;
        if(a==2)
            return mypow(b)*(long long)2%1000000007;
        return mypow(b);
    }
};
```