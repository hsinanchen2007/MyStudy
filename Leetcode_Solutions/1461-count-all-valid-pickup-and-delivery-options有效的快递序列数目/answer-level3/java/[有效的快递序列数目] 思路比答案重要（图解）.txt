想不出来是因为你没有写写画画~ 
来比划一下 n=1 和 n=2 的情况一切就清楚了。
# **n=1**:
毫无疑问答案只有 **(P1 D1)** 这一种情况。
# **n=2**:
我们知道答案其实就是 **{P1 D1 P2 D2}** 的某些排列，这些排列只需要满足 P1 在 D1 之前，P2 在 D2 之前即可。
也就是说!在 **(P1 D1)** 的基础上，我们随便把 P2 和 D2 插空进去（当然，要保持 P2 在 D2 的前面），就得到了一个答案。
比如我们可以这样插
![image.png](https://pic.leetcode-cn.com/527be40505ff8675459d58c320fe8c4de656799ed1f310d2252e8a78ecfec762-image.png)
也可以这样插
![image.png](https://pic.leetcode-cn.com/d0f951d74be934320491eb9c6d38cf508dad0f38669acd3835bac72cfdcd34a0-image.png)
等等……
那一共有多少中插空的方法呢？不难发现这是个排列组合问题，从四个位置中选两个位置 ,C(2,4)=6 。
如果我们把答案记为 F[n] 的话，那 F[2] 其实就是在 F[1] 每一个答案序列基础上再乘以 6 种不同的插空数。由于 F[1]=1 ，所以 `F[2]=1*C(2,4)=6`。

以此类推得到
```
F[3]=F[2]*C(2,6)=90 ,
F[4]=F[3]*C(2,8)=2520,
F[n]=F[n-1]*C(2,2n)
=F[n-1]*n*(2*n-1).
```

有了递推公式，code就呼之欲出了。注意由于 F[n]只跟 F[n-1]有关，我们可以省下这个数组的空间。

```java
class Solution {
    int mod=1000000007;
    public int countOrders(int n) {
        long last=1;
        for(int i=1;i<=n;i++){
            //组合 C(2,2*i)
            int c=i*(2*i-1);
            last=(last*c) % mod;
        }
        return (int)last;
    }
}
```







