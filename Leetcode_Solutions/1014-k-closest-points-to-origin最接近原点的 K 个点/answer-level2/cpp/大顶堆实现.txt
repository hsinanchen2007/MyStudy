### 解题思路
大顶堆实现

### 代码

```cpp
class Solution {
private:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> greaterHeap;

        for (auto each : points) {
            greaterHeap.push(make_pair(each.front(), each.back()));
            if (greaterHeap.size() > K) {
                greaterHeap.pop();
            }
        }

        vector<vector<int>> result;
        while (!greaterHeap.empty()) {
            result.push_back({greaterHeap.top().first, greaterHeap.top().second});
            greaterHeap.pop();
        }

        return result;
    }
};
```