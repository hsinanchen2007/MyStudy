# 方法一：
大顶堆
```
class Solution {
public:
    struct P {
        int u, v, s;
        P(int _u, int _v) : u(_u), v(_v), s(_u + _v) {};
    };
    struct Cmp {
        bool operator() (const P& p1, const P& p2) const {
            return p1.s <= p2.s;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, Cmp> q;
        for (auto u : nums1) {
            for (auto v : nums2) {
                q.push(P(u, v));
                if (q.size() > k) q.pop();
            }
        }
        vector<vector<int> > res;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            res.push_back({p.u, p.v});
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/b377e059f925015ed8d318f2550064e918e35c5d34f21a76e463783abc22202d-image.png)

# 方法二：
二分搜索
```
class Solution {
public:
    int bisearch(vector<int>& nums, int t) {
        if (nums[0] > t) return -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (nums[m] <= t) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        int low = nums1.front() + nums2.front();
        int high = nums1.back() + nums2.back();
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < nums1.size(); ++i) {
                int t = bisearch(nums2, mid - nums1[i]);
                if (t < 0) break;
                count += t + 1;
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        vector<vector<int> > res;
        vector<vector<int> > edge;
        for (int i = 0; i < nums1.size(); ++i) {
            int t = bisearch(nums2, high - nums1[i]);
            if (t < 0) break;
            for (int j = 0; j <= t; ++j) {
                if (nums1[i] + nums2[j] == high) {
                    edge.push_back({nums1[i], nums2[j]});
                } else {
                    res.push_back({nums1[i], nums2[j]});
                }
            }
        }
        while (res.size() < k && !edge.empty()) {
            res.push_back(edge.back());
            edge.pop_back();
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d91cef2a5248b1477c2c62f112e7ffff26a75a6d7b1f2a85b4d4a9402802bb9a-image.png)
