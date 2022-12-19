### 解题思路
需要重载一下运算符，复习了一下语言特性

### 代码

```cpp
class Solution {
public:
    struct cmp {
        bool operator () (vector<int> & a, vector<int> & b) {
            return pow(long(a[0]),2)+pow(long(a[1]),2) < pow(long(b[0]),2)+pow(long(b[1]),2);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> re;
        if (points.empty()) return re;
        priority_queue<vector<int>, vector<vector<int>>, cmp> que;
        for (int i=0; i<points.size(); i++) {
            que.push(points[i]);
            if (que.size()>K) que.pop();
        }
        while (!que.empty()) {
            re.push_back(que.top());
            que.pop();
        }
        return re;
    }
};
```