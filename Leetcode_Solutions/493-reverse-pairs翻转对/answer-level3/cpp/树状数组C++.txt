与逆序数很像，归并和树状数组都可以套用.
下面是使用树状数组的解法

```
class TreeArray {
public:
    vector<int> tree;
    int len;
    
    TreeArray(int n) {
        len = n;
        tree = vector<int>(n+1);
    }
    
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
    
    void update(int i, int v) {
        while (i <= len) {
            tree[i] += v;
            i += lowbit(i);
        }
    }
    
    int lowbit(int i) {
        return i & (-i);
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int size = (int)nums.size();
        if (size <= 1) {
            return 0;
        }

        set<int> s;
        TreeArray treeArray = TreeArray(size);
        for (auto n : nums) {
            s.emplace(n);
        }
        int rank = 1;
        map<int, int> m;
        for (auto n : s) {
            m.emplace(n, rank);
            rank++;
        }
        int res = 0;
        for (int i =(int)nums.size()-1; i>=0; i--) {
            int n = nums[i];
            int target = n / 2;
            if (n > 0) {
                target = (int)(((long long)n + 1) / 2); //向上取整
            }
            auto low = s.lower_bound(target);
            if (low != s.begin()) {
                res += treeArray.query(m[*(--low)]);
            }
            treeArray.update(m[n], 1);

        }
        return res;
    }
};
```