```C++ []
class Solution {
public:
    struct Node {
        int ind;
        int val;
        Node(int i, int v) : ind(i), val(v) {}
        bool operator < (const Node& other) const {
            return this->val < other.val;
        }
    };
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int N = intervals.size();
        vector<Node> nodes;
        for (int i = 0; i < N; ++i) {
            nodes.push_back(Node(i, intervals[i][0]));
        }
        sort(nodes.begin(), nodes.end());
        vector<int> v(N, 0);
        for (int i = 0; i < N; ++i) {
            v[i] = nodes[i].val;
        }
        vector<int> res(N, -1);
        for (int i = 0; i < N; ++i) {
            auto it = lower_bound(v.begin(), v.end(), intervals[i][1]);
            if (it != v.end()) {
                res[i] = nodes[it - v.begin()].ind;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d43288d2c792286fb788420e599af67b1c58980cfabf09803ab76c8ca4152fb4-image.png)
