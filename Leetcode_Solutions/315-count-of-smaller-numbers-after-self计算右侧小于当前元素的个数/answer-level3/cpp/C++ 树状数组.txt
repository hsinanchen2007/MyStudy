树状数组题解
树状数组(Binary Indexed Tree (BIT))题解
1，数组离散化为其本身rank
2，然后从后向前遍历，并不断更新数组

```
class Solution {
public:
    vector<int> bits;
    int N;
    void add(int i, int x) {
        while (i <= N) {
            bits[i] += x;
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bits[i];
            i -= i & -i;
        }
        return res;
    }
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        map<int, int> m;
        for (auto x : s) {
            m[x] = m.size() + 1;
        }
        vector<int> ranks(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            ranks[i] = m[nums[i]];
        }
        N = ranks.size() + 1;
        bits = vector<int>(N + 1, 0);
        vector<int> res;
        for (int i = ranks.size() - 1; i >= 0; --i) {
            res.push_back(query(ranks[i] - 1));
            add(ranks[i], 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/9edda0719d8ffc4e05a65816ab9bd0f8602fea7749346bcdb2954fec1f50f160-image.png)
