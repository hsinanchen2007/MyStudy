本题的模型转化一下，就是求任意时间点上最多有几个区间相交。
想到了差分解决。
预计数据范围不超过 1e6， 所以牺牲内存（虽然没怎么优化时间)
开一个长度 10^6 差分数组
遍历开会时间对，在差分数组上打上标记，因为这道题结束时间计算方式比较特殊，差分标记比较特殊。
打完标记后更新差分数组，最后找到区间最多的时间点就好了。。
时间数据再大点就没了。。时间不优雅、空间不优雅，只是个猎奇的解法。
```
class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        if (n == 0) return 0;
        int f[1000005], mxx = 0;
        memset(f, 0, sizeof f);
        for (auto x : intervals)
        {
            f[x[0]] ++; f[x[1]] --;
            mxx = max(x[1], mxx);
        }
        for (int i = 1; i <= mxx; ++ i)
            f[i] += f[i - 1];
        int ans = 0;
        for (int i = 0; i <= mxx; ++ i)
            ans = max(ans, f[i]);
        return ans;
    }
};
```
