- 参考大佬的思路：[Ikaruga](https://leetcode-cn.com/problems/maximum-performance-of-a-team/solution/5359-by-ikaruga/)
- 按照效率 $\eta_i$ 降序排序，遍历每个人
- 最大团队值为 $\min \eta_i*\sum speed$
- $\eta_i$ 是下降的，那么效率高于 $\eta_i$ 的人在人数少于 $k$ 的时候全部加入，使得第二项最大
- 当人数超过 $k$ 了，在 $\eta_i$ 下，比其效率高的人中，我要选出 $speed$ 最大的 $k$ 人
- 这样，每个 $\eta_i$ 作为第一项的情况 都遍历过了，且每次遍历的时候，挑出来的人也都是 $speed$  最快的

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> people;
        int i, e, s;
        long long maxPerf = 0, speedsum = 0;
        for(i = 0; i < speed.size(); ++i)
        {
        	people.push_back({efficiency[i], speed[i]});
        }

        sort(people.rbegin(), people.rend());//按照效率从大到小排序
        priority_queue<int, vector<int>,greater<int>> q;//小顶堆
        for(i = 0; i < speed.size(); ++i)
        {
        	e = people[i][0];//效率
        	speedsum += people[i][1];//速度和
        	k--;//人数-1
        	q.push(people[i][1]);//速度队列，堆顶最小
        	if(k < 0)//人超过k人了
        	{
        		speedsum -= q.top();//速度小的删除
        		q.pop();
        	}
        	maxPerf = max(maxPerf, e*speedsum);//这里不要取模
        }
        return maxPerf%1000000007;
    }
};
```