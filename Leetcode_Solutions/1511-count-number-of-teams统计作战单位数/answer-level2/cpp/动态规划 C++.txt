参考了[@chx2502](/u/chx2502/)的题解，然后自己写了一下代码
用动态规划做：
现在先考虑第一种情况 `rating[i] < rating[j] < rating [k]`
我们用dp[i]表示在rating[i]左边比它小的元素个数
那么我们在i这个位置的时候，从i-1往左遍历，`挨个看看rating[j](j=0,1,···,i-1)是否比rating[i]小`，如果比rating[i]小的话那dp[i]就+1

那知道dp[i]等于多少有什么用呢？怎样求以dp[i]结尾的作战单位的数量呢？
首先要明确的是，只有（1）rating[i] > rating[j]，且（2）dp[j] > 0 的时候，才能以dp[i]结尾并组成作战单位
（1）rating[i] > rating[i]就不用解释了，因为我们第一种情况就是这么要求的
（2）而对于dp[j] > 0，也就是dp[j]至少要等于1，也就是说前面至少有1个元素比rating[j]小。那么加上rating[j]这个元素，那就有至少2个元素比rating[i]小了。再加上rating[i]就可以组成作战单位了

所以，在`挨个看看rating[j](j=0,1,···,i-1)是否比rating[i]小`的时候，还要看看dp[j]是否大于0
如果dp[j]=k，k大于0，则说明dp[j]前面有k个比rating[j]小的数，那这k个数就可以和rating[j]，rating[i]组成k个作战单位了。


对于第二种情况`rating[i] > rating[j] > rating [k]`，其实跟第一种情况相反的，两种情况是可以放到一个循环里的，你从rating数组右边开始向左走就可以了。
需要注意的是，因为第一种情况和第二种情况的dp是相互独立的，所以要有两个数组，下面代码里分别是forward和backward。

```
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        vector<int> forward;
        forward.push_back(0);
        vector<int> backward;
        backward.push_back(0);
        for(int i = 1, p = n-2; i < n && p >= 0; i++,p--){
            
            forward.push_back(0);
            for(int j = i-1; j >= 0; j--){
                if(rating[i] > rating[j]){
                    forward[i] += 1;
                    if(forward[j] > 0) ans += forward[j]; 
                }
                
            }
            
            backward.push_back(0);
            for(int q = p + 1; q < n; q++){
                if(rating[p] > rating[q]){
                    backward[n-1-p] += 1;
                    if(backward[n-1-q] > 0) ans += backward[n-1-q];
                }
            }
        }

        return ans;
    }
};
```
