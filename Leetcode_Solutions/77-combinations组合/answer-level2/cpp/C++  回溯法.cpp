### 解题思路
直接进行回溯

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        int start = 1;
        traceback(res, tmp, n, k, start);
        return res;
    }

    void traceback(vector<vector<int>>& res, vector<int> tmp, int n, int k, int start) {
        if (tmp.size() == k) {
            res.push_back(tmp);
        } else {
            for (int i = start; i <= n; i++) {
                tmp.push_back(i);
                traceback(res, tmp, n, k, i+1);
                tmp.pop_back();
            }
        }
    }
};
```

欢迎关注微信公众号'码农黑板报'，一起学习交流算法