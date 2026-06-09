我们把示例2拿出来重新按工作的结束时间排序，如图所示：![无标题.png](https://pic.leetcode-cn.com/e09c2b91352cfe7265612673014232ec2d1dac1d8e798408ee5228c9240586bd-%E6%97%A0%E6%A0%87%E9%A2%98.png)
具体来说：
我们使用一个`dp`数组，`dp[i]`表示做包括`i`号工作之前的所有工作能取得的最大收益
　再使用一个`prev`数组，`prev[i`]表示`i`号工作之前最近能做的工作
0号工作之前没有能做的工作了，所以`prev[0]=0;`
1号工作之前没有能做的工作了，所以`prev[1]=0;`
2号工作之前没有能做的工作了，所以`prev[2]=0;`
3号工作之前最近能做的工作是1，所以`prev[3]=1;`
4号工作之前最近能做的工作是3，所以`prev[4]=3;`
5号工作之前最近能做的工作是1，所以`prev[5]=1;`

对于每个兼职工作，都有做与不做两种状态：
一.假如我们做`1`号工作，能够获得`20`元，加上在`1`号工作之前最近能做的`0`号工作(虚拟的工作，收益也是`0`)的最大收益`0`元；如果不做`1`号工作，能够获得收益是`0`，于是做包括`1`号工作之前的所有工作能取的最大收益就是两中情况的最大值`20`。
二.假如我们做`5`号工作，能够获得收益是`100`，加上在`5`号工作之前最近能做的`prev[5]=1`号工作的最大收益`dp[1]`；如果不做`5`号工作，能够获得收益就是做剩余`4`个工作最大收益`dp[4]`，于是做包括`5`号工作之前的所有工作能取的最大收益就是两中情况的最大值=`max(dp[1]+profit[5],dp[4])`。

所以状态转移方程就是
```
dp[i]=max(dp[i-1],dp[prev[i]]+profit[i])
```
具体到题目中来说，由于题目的输入导致一些不同，我们可以开一个二维数组`vector<vector<int>>job;`把开始时间、结束时间和收益拷贝过来，再把这个二维数组排成如图所示的顺序，但是这样效率不高，因为拷贝也是要花时间的，一个比较好的办法直接对下标排序获得如图所示的顺序。

prev数组的获得是直接向前遍历，找第一个结束时间小于等于当前工作开始时间的工作，感觉这里应该还是有优化的空间的。

由于加入了一个虚拟的0号工作，所以下标还有些变化，具体看代码。这个工作到底有没么必要加呢，如果你有解决方案请告诉我。
```
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>job(n+1);
        iota(job.begin(), job.end(), 0);
        sort(job.begin()+1, job.end(), [&](int& a, int& b) {return endTime[a-1]< endTime[b-1]; });
        vector<int>prev(n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = i - 1; j >= 1; j--)
                if (endTime[job[j]-1] <=startTime[ job[i]-1])
                {
                    prev[i] = j;
                    break;
                }
        vector<int>dp(n + 1);
        dp[1] = profit[job[1]-1];
        for (int i = 1; i <= n; i++)
            dp[i] = max(dp[i - 1], profit[job[i]-1] + dp[prev[i]]);
        return dp[n];
    }
};
```

