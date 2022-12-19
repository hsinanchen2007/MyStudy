### 解题思路
此处撰写解题思路

### 方法一代码：深度优先搜索
```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        path = vector<int>(k);
        dfs(0, 1, k, n);
        return ans;
    }

    void dfs(int cur,int num, int k, int n) {
        if (cur == k) {
            int sum = 0;
            for (int j = 0; j < k; j++) sum += path[j];
            if (sum == n) ans.push_back(path);
            return;
        }

        for (int i = num; i <= 9; i++) {
            path[cur] = i;
            dfs(cur + 1, i + 1, k, n);
        }
    }
};
```

这是一道相对基础的题，注意深度优先搜索的时候，后一个位置放的数字要比前一个位置大。
中途遍历的时候可以让，path数组固定大小，每次递归在自己的位置上放置数字，这样省略了一个回溯的过程。

### 方法二代码：暴力遍历
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        ans.push_back({0});

        while (ans[0].size() < k) {
            vector<vector<int>> path;
            for (auto vec : ans) {

                int start = vec[0] ? vec.back() : 0;

                for (int i = start + 1; i < 10; ++i) {
                    vector<int> tmp;
                    if (vec[0]) tmp = vec;
                    else tmp = {};
                    tmp.push_back(i);
                    path.push_back(tmp);
                }

            }
            ans = path;
        }

        vector<vector<int>> res;

        for (auto v :ans) {
            int sum = 0;
            for (auto item : v) {
                sum += item;
            }
            if (sum == n) res.push_back(v);
        }
        return res;
    }
};
```
这种方法效率没有方法一高，慎用。