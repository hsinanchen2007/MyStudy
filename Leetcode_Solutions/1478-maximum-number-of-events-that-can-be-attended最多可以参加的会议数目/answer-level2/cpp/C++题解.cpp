### [5342. 最多可以参加的会议数目](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/)

### 题解
   + 首先给所有会议按开始时间从先到后排序
   + 统计天数最大值$maxd$
   + 将日期从1遍历到$maxd$, 将符合条件的区间都丢入堆，取出会议结束时间最早的会议进行匹配
   + 累加会议数
   + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

### 代码
```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [&](vector<int> x, vector<int> y){
            return x[0] < y[0];
        });
        int res = 0;
        int maxd = 0;
        for(int i = 0; i < events.size(); i++)
          maxd = max(maxd, events[i][1]);
        int j = 0;
        priority_queue<int, vector<int>, greater<int> > que;
        for(int i = 1; i <= maxd; i++)
            {
                for(; j < events.size() && events[j][0] <= i; j++)
                        que.push(events[j][1]);
                while(!que.empty())
                {
                    int t = que.top();
                    que.pop();
                    if(t >= i) {res++; break;}
                }
            }
        return res;
    }
};
```