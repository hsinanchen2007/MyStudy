### 解题思路
利用优先队列构造一个大顶堆，维护k个元素


### 代码

```cpp
class Solution {
public:
    struct cmp {
        bool operator () (pair<int, int>& a, pair<int, int>& b) {
            
            int resA = pow(a.first, 2) + pow(a.second, 2);
            int resB = pow(b.first, 2) + pow(b.second, 2);
            return resA < resB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // 距离最近，需要构造大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        int size = points.size();
        vector<vector<int>> ans;
        if (size == 1) {
            vector<int> tmp = {points[0][0], points[0][1]};
            ans.push_back(tmp);
            return ans;
        }
        
        for (int i = 0; i < size; i++) {
            if (i < K) {
                pq.push({points[i][0], points[i][1]});
            } else {
                int res = pow(points[i][0], 2) + pow(points[i][1], 2);
                int x = pq.top().first;
                int y = pq.top().second;
                int topVal = pow(x, 2) + pow(y, 2);
                if (res < topVal) {
                    pq.pop();
                    pq.push({points[i][0], points[i][1]});
                }
            }
        }
        while (!pq.empty()) {
            int x = pq.top().first;
            int y = pq.top().second;
            
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};
```