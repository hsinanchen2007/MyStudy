### 解题思路
最开始想的是按照开始时间最短排列，忽略了[1,99] [2,2] [2,3]这个反例。于是想到，如果能知道当天能参加哪些会议，然后挑选其中结束最早的那个会议进行参加，应该是最划算的。

因此，需要一个优先队列，用于存储当前结束时间最早的回忆；遍历每个会议，每次将当前能够参加的会议压入队列，然后选择合法的队列进行参加。

### 代码

```cpp
class Solution {
public:
    struct node{
        int startDay;
        int endDay;
        node(int istartDay, int iendDay) {
            startDay = istartDay;
            endDay = iendDay;
        }
    };
    struct cmp {
        bool operator() (node a, node b) {
            return a.endDay > b.endDay;
        }
    };
    
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<node, vector<node>, cmp> eventQueue;
        sort(events.begin(), events.end(),[](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        int ans = 0;
        int cDay = events[0][0];
        int index = 0;
        while( index < events.size() || ! eventQueue.empty()) {
            while(index < events.size() && cDay == events[index][0]) {
                eventQueue.push(node(events[index][0], events[index][1]));
                index++;
            }
            while(! eventQueue.empty() && eventQueue.top().endDay < cDay) {
                eventQueue.pop();
            }
            if (! eventQueue.empty()) {
                ans++;
                eventQueue.pop();
            }
            cDay++;
        }
        return ans;
    }
};
```