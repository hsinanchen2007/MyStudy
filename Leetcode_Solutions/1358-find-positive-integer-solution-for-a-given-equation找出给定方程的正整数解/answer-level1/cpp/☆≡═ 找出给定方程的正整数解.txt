双指针
```
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, const int z) {
        vector<vector<int>> ans;
        for (int i = 1, j = 1000; i <= 1000 && 1 <= j;) {
            const int val = customfunction.f(i, j);
            if (val == z) {
                ans.push_back({i, j});
                ++i, --j;
            } else if (val < z) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
```

二分查找
```
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, const int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; x++) {
            int l = 1, r = 1001, m = l + (r - l)/2, t = numeric_limits<int>::min();
            while (l < r) {
                t = customfunction.f(x, m);                
                if (t == z) {
                    break;
                } else if (t < z) {
                    l = m + 1;
                } else {
                    r = m;
                }
                m = l + (r - l)/2;
            }
            if (t == z) ans.push_back(vector<int>{x, m});
            if (customfunction.f(x, 1) > z) break;
        }
        return ans;
    }
};
```
