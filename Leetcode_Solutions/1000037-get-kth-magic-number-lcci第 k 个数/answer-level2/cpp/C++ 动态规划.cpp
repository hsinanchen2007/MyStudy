这个题目，很类似丑数这道题。可以认为是一类问题：
3,5,7三个元素是互为素数的情况下，如何求得从小大到大的情况下的第n个数。
首先第1个数是1。
接下来思考这个问题：假设我们现在已经有了k个数(num[0],num[1]……num[k-1])，我们怎么找第k+1个数呢？
先暴力来做：我们用3,5,7分别乘k个数，找到第一个大于num[k-1]的数作为第k+1个数。
这样的确可以，但是可不可以优化下呢?
思考下：
    num[k-1]也是由3,5,7乘一个数得来的
    假设num[k-1]是由3*nums[i](i<k-1)得来的
    那么在求num[k]的时候，我们只需要3*num[i+1]即可，因为前面的肯定是不满足的.

因此我们通过三个指针pa,pb,pc来获得第n个数。
pa:表示3下一个扩展位置
pb:表示5下一个扩张位置
pc:表示7下一个扩展位置
那么第n个数就是：min(3*num[pa],min(5*num[pb],7*num[pc]));
如果nums[n-1]是由3*num[pa]得来的，pa+=1,是由5*num[pb]得来的，pb+=1。
重复这个过程，直至求出nums[n-1]

代码如下：
```
class Solution {
public:
    int getKthMagicNumber(int k) {
        if(k==0) return 1;
        vector<int>dp(1,1);
        int pa=0,pb=0,pc=0,s=1;
        while(s++<k){
            int tmp=min(3*dp[pa],min(5*dp[pb],7*dp[pc]));
            if(tmp==3*dp[pa]) pa++;
            if(tmp==5*dp[pb]) pb++;
            if(tmp==7*dp[pc]) pc++;
            dp.push_back(tmp);
        }
        return dp.back();
    }
};
```
