### 解题思路
1.统计所有元素频率O(n)
2.所有元素pair入堆(优先队列)
3.前k元素出堆

### 代码

```cpp
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mm;
        for (auto i : nums) {
            if (mm.find(i) == mm.end()) mm[i] = 0;
            mm[i]++;
        }
        struct cmp {
            bool operator() (pair<int, int> left, pair<int, int> right) {
                return left.second < right.second; 
            }
        };
        //priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        priority_queue<pair<int, int>, deque<pair<int, int>>, cmp> q;
        for (auto it = mm.begin(); it != mm.end(); it++) {
            q.push(std::make_pair(it->first, it->second));
        }
        vector<int> res;
        while (!q.empty() && k > 0) {
            res.push_back(q.top().first);
            q.pop();
            k--;
        }
        return res;
    }
};
```