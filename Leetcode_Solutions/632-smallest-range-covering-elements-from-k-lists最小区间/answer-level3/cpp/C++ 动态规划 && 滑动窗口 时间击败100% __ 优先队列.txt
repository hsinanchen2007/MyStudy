## 思路一 动态规划 && 滑动窗口
时间复杂度：O(NLOG(N)) // 排序开销
空间复杂：O(N) // vn数组的开销
```cpp
class node {
    public:
        int value;
        int index;
        node (int _value, int _index) {
            value = _value;
            index = _index;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();
        vector<node> vn;
        for (int i = 0; i < k; i++) {
            auto &arr = nums[i];
            for (auto num : arr) {
                vn.push_back(node(num, i));
            }
        }
        // 按照值排序
        sort(vn.begin(), vn.end(), [](const node &lhs, const node &rhs){
            return lhs.value < rhs.value;
        });
        vector<int> dp(k, 0);
        int found = 0;
        int l = 0;
        int r = 0;
        dp[vn[0].index]++;
        found = 1;
        const int size = vn.size();
        int lret = 0;
        int rret = size - 1;
        while (l < size && r < size) {
            // 窗口右界滑动直到到达最后或者k个数组都已经找到
            while (found < k && r < size - 1) {
                r++;
                dp[vn[r].index]++; // 标记index数组中的当前命中数目
                if (dp[vn[r].index] == 1) { // 一个新的index数组命中
                    found++;
                }
            }
            if (found != k) // 已经到达边界
                break;
            while (found == k && l <= r) { // 左界在此右移到达临界状态
                dp[vn[l].index]--;          
                if (dp[vn[l].index] == 0) {
                    found--;
                    // 更新结果
                    if (vn[r].value - vn[l].value < vn[rret].value - vn[lret].value) {
                        rret = r;
                        lret = l;
                    }
                }
                l++; 
            }
        }
        return {vn[lret].value, vn[rret].value};
    }
};
```

## 思路二 优先队列
```cpp
class node {
public:
    int row;
    int col;
    int val;
    node(int ir, int ic, int iv) {
        row = ir;
        col = ic;
        val = iv;
    }
};

class cmp {
public:
    bool operator() (const node &lhs, const node &rhs) {
        return lhs.val > rhs.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node, vector<node>, cmp> pqn;
        const int k = nums.size();
        int max = -INT_MAX;
        for (int i = 0; i < k; i++) {
            if (nums[i][0] > max) {
                max = nums[i][0];
            }
            pqn.push(node(i, 0, nums[i][0]));            
        }
        int lret = 0;
        int rret = INT_MAX;
        bool has_next = true;
        do {
            auto min = pqn.top();
            pqn.pop();
            //cout << min.val << "," << max << endl;
            if (max - min.val < rret - lret) {
                lret = min.val;
                rret = max;
            }
            min.col++;
            if (min.col >= nums[min.row].size()) {
                has_next = false;
            } else {
                min.val = nums[min.row][min.col];
                if (max < min.val)
                    max = min.val;
                pqn.push(min);
            }
        } while(has_next);
        return {lret, rret};
    }
};
```
使用Lambda表达式简化一下代码
```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();
        vector<int> dp(k, 0);
        auto cmp = [&](const int &lhs, const int &rhs){
            return nums[lhs][dp[lhs]] > nums[rhs][dp[rhs]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pqn(cmp);
        int max = -INT_MAX;
        for (int i = 0; i < k; i++) {
            if (nums[i][0] > max) {
                max = nums[i][0];
            }
            pqn.push(i);
        }
        int lret = 0;
        int rret = INT_MAX;
        bool has_next = true;
        do {
            auto min = pqn.top();
            pqn.pop();
            if (max - nums[min][dp[min]] < rret - lret) {
                lret = nums[min][dp[min]];
                rret = max;
            }
            dp[min]++;
            if (dp[min] >= nums[min].size()) {
                has_next = false;
            } else {
                if (max < nums[min][dp[min]])
                    max = nums[min][dp[min]];
                pqn.push(min);
            }
        } while(has_next);
        return {lret, rret};
    }
};
```