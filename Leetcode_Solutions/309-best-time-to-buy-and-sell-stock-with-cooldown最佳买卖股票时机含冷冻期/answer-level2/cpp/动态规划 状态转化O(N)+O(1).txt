# 状态
首先对于当天来说有四种可能的状态：卖出、买入、冷冻（卖出后到买入前都叫冷冻）、持有（买入后到卖出前都叫持有）。
这四种状态可以相互转化，分别以a,b,c,d表示：
![image.png](https://pic.leetcode-cn.com/a6ebed1a4b7bf3ef454914e295cd1564877b9c89416dd6cf48b3425f4286d0e6-image.png)
a[i] 表示当天是最后一天，且决定卖出，所获得的最大值。
b[i] 表示当天是最后一天，且决定买入，所获得的最大值。
c[i] 表示当天是最后一天，且决定冷冻，所获得的最大值。
d[i] 表示当天是最后一天，且决定持有，所获得的最大值。
每天更新a,b,c,d:
``` cpp
a[i] = max(d[i-1], b[i-1]) + prices[i]
b[i] = c[i-1] - prices[i]
c[i] = max(c[i-1], a[i-1])
d[i] = max(d[i-1], b[i-1])
```
这样就把上图7个转移过程都给表述出来了，但是这样空间占用是 $O(4N)$ 级别，只要压缩空间，分析一下a,b,c,d之间的依赖，就可以将空间压缩到 $O(1)$。
很明显，最后一天结束后，我们的收入最大值只能在a,c之中取得。所以最后一天取a,c的最大值就可以。

还有一个最大的问题：初始化，第一天的时候，b,c很容易，`b=-prices[0];c=0;`，而a是不能卖出的（因为根本没有买，所以`a=0;`），而如果是持有的话，因为之前没有买，此处持有应当认为当天买了（这样后面的推算才能开始），所以`d=-prices[0];`。初始化结束之后，直接推就可以。


代码如下：

``` cpp
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n == 0) return 0;
        int a,b,c,d;
        a = 0;
        b = -prices[0];
        c = 0;
        d = -prices[0];
        for(int i=1;i<n;++i){
            d = b > d ? b : d;
            b = c - prices[i];
            c = a > c ? a : c;
            a = d + prices[i];
        }
        return a > c ? a : c;
    }
```