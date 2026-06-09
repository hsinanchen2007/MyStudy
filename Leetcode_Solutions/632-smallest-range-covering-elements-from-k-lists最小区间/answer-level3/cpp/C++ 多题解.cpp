解法一：
排序数组，并记录数的来源，然后滑动窗口求解。
```
class Solution {
public:
    struct Cmp {
        bool operator() (const vector<int>& v1, const vector<int>& v2) const {
            return v1[0] > v2[0];
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int> >, Cmp> pq;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                pq.push({nums[i][j], i});
            }
        }
        map<int, int> counts;
        queue<vector<int> > q;
        int l = INT_MAX;
        int r = INT_MIN;
        int res_l = 0;
        int res_r = INT_MAX;
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            r = max(r, v[0]);
            l = min(l, v[0]);
            ++counts[v[1]];
            q.push(v);
            while (counts.size() == N && counts[q.front()[1]] > 1) {
                --counts[q.front()[1]];
                q.pop();
                l = q.front()[0];
            }
            if (counts.size() == N && r - l < res_r - res_l) {
                res_l = l;
                res_r = r;
            }
        }
        return {res_l, res_r};
    }
};
```

解法二：
最小堆，逐渐更新区间
```

class Solution {
public:
    struct Node {
        int val;
        int ind;
        int arr;
        Node(int v, int i, int a) : val(v), ind(i), arr(a) {};
        bool operator < (const Node& other) const {
            return val > other.val;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node> pq;
        int N = nums.size();
        int l = INT_MAX;
        int r = INT_MIN;
        int min_range = INT_MAX;
        for (int i = 0; i < N; ++i) {
            pq.push(Node(nums[i][0], 0, i));
            l = min(l, nums[i][0]);
            r = max(r, nums[i][0]);
        }
        int res_l = l;
        int res_r = r;
        while (true) {
            auto node = pq.top();
            pq.pop();
            if (node.ind == nums[node.arr].size() - 1) {
                break;
            }
            node.val = nums[node.arr][++node.ind];
            pq.push(node);
            r = max(r, node.val);
            l = pq.top().val;
            if (r - l < res_r - res_l) {
                res_l = l;
                res_r = r;
            }
        }
        return {res_l, res_r};
    }
};
```

解法三：
多指针

```
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int N = nums.size();
        int l = INT_MAX;
        int r = INT_MIN;
        vector<int> fronts(N, 0);
        for (int i = 0; i < N; ++i) {
            r = max(r, nums[i][0]);
            l = min(l, nums[i][0]);
            fronts[i] = nums[i][0];
        }
        int res_l = l;
        int res_r = r;
        vector<int> indices(N, 0);
        while (true) {
            for (int i = 0; i < N; ++i) {
                while (indices[i] < nums[i].size() && nums[i][indices[i]] == l) ++indices[i];
                if (indices[i] == nums[i].size()) return {res_l, res_r};
                fronts[i] = nums[i][indices[i]];
                r = max(r, fronts[i]);
            }
            l = *min_element(fronts.begin(), fronts.end());
            if (r - l < res_r - res_l) {
                res_r = r;
                res_l = l;
            }
        }
        return {res_l, res_r};
    }
};
```
![image.png](https://pic.leetcode-cn.com/2e3a1a74368d1c3394144145859df11daccd99b021e58a2cfefe27fc68070d61-image.png)
