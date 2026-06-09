### 解题思路
贪心+优先队列

### 代码

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());

        //multiset从小到大 priority_queue从大到小
        multiset<int> s;
        int i=1;
        int j=0;
        int ans=0;

        while(j<n || !s.empty())
        {
            //把第i天开始的会议结束时间加入，从小到大排序
            while(j<n && events[j][0]==i)
            {
                s.insert(events[j][1]);
                j++;
            }
            //把第i天之前结束的会议删掉
            while(!s.empty() && *s.begin()<i)
            {
                s.erase(s.begin());
            }
            
            //如果还有可用会议，就是当前可用的结束时间最前的会议，贪心取并删除
            if(!s.empty())
            {
                s.erase(s.begin());
                ans++;
            }
            i++;
        }
        return ans;
    }
};
```