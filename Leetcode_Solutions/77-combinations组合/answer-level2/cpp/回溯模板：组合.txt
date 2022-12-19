### 解题思路


### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty;
        backtrack(empty, 1, n, k);
        return res;
    }
    
    void backtrack(vector<int> cur, int i, int n, int k) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        // 用 j 枚举追加的最小的数字
        for(int j=i; j<=n; j++) {
            cur.push_back(j);
            backtrack(cur, j + 1, n, k);
            cur.pop_back();
        }
    }
};
```

使用如下代码在第26个用例会超时，C(20, 16)：

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty;
        backtrack(empty, 1, n, k);
        return res;
    }
    
    void backtrack(vector<int> cur, int i, int n, int k) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        // 剪枝
        if(cur.size() > k)
            return;
        // 边界
        if(i == n + 1)
            return;
        // 不加入当前数字
        backtrack(cur, i + 1, n, k);
        // 加入当前数字
        cur.push_back(i);
        backtrack(cur, i + 1, n, k);
        cur.pop_back();
    }
};
```
