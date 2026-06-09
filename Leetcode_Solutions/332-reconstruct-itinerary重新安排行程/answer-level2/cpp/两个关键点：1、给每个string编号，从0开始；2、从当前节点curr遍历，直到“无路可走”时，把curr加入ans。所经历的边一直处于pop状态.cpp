### 解题思路
画个图例感受下！

### 代码

```cpp

class Solution {
public:
    struct cmp
    {
        bool operator()(const string& a, const string& b) {
            return a > b;
        }
    };
 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, int> m;
        vector<priority_queue<string, vector<string>, cmp > > queues; // 10
        for (auto p : tickets) {
            if (m.find(p[0]) == m.end()) {
                priority_queue<string, vector<string>, cmp> newQueue;
                newQueue.push(p[1]);
                queues.push_back(newQueue);
                m.insert(make_pair(p[0], queues.size() - 1));
            }
            else {
                queues[m[p[0]]].push(p[1]);
            }
        }
 
        vector<string> ans;
        stack<string> s;
        s.push("JFK");
 
        while (!s.empty()) {
            string curr = s.top();
            if (m.find(curr) == m.end() || queues[m[curr]].size() == 0) { // 20
                ans.push_back(curr);
                s.pop();
            }
            else {
                s.push(queues[m[curr]].top());
                queues[m[curr]].pop();
            }
        }
 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```