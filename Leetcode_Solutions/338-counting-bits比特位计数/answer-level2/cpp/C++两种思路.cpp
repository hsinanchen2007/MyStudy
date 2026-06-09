提供几种思路
最容易想到的当然是 暴力 的解法!
# 方法一
那么如何计算`n`的二进制表示中1的个数呢?
我们**从右向左**看,找到第一个为1的bit位,将这一位置为0. 
重复上述过程,统计操作的次数,就得到了1的个数.
那么如何实现上述操作呢?

我们不妨考虑下`n`和`n-1`之间的关系
20=10**100**
19=10**011**
看到木有,从右向左看第一1以及之后的bit位恰好相反,而在这个1之前的bit位不变.
因此20&19的结果,由二进制表示,可以算出为10000,我们将最右边的1去掉了,重复该过程.直到`n`变为0
```cpp
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=1;i<=num;i++){
            ans[i]=cnt(i);
        }
        return ans;
    }
    int cnt(int n){
        int sum=0;
        while(n){
            sum+=1;
            n&=(n-1);
        }
        return sum;
    }
```

# 方法二
每个`n`位的二进制数与`n-1`的二进制数表示,仅有最后一位不同.从而,若记f(n)为n的二进制表示中1的个数,那么f(n/2)与n只有最后一位不同
若n为奇数,则比n/2的二进制表示多一个1
否则,和n/2的二进制表示相等
```cpp
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=1;i<=num;i++){
            ans[i]=ans[i/2]+i%2;
        }
        return ans;
    }

```

