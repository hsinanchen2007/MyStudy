### 解题思路
详见代码注释

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    void inner(int k, int n, vector<int>& data, int level, vector<int>& path, vector<vector<int>>& res) {
      // 和全排列的区别在于，这里面只到k层
      if (level == k) {
        // 常规判断搜索到的结果之和是否为n
        int sum = 0;
        for (int& val : path) {
          sum += val;
        }
        if (n == sum) {
          res.push_back(path);
        }
        return;
      }

      for (int i = level; i < 9; ++i) {
        // 这个条件很关键，保证搜索到的结果是升序的，其他的都会被剪枝掉
        if (path.empty() || path.back() < data[i]) {
          // 类似全排列的回溯
          swap(data[level], data[i]);
          path.push_back(data[level]);
          inner(k, n, data, level + 1, path, res);
          path.pop_back();
          swap(data[level], data[i]);
        }
      }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> res;
      // k只能为1-9
      if (k >= 10 || k <= 0) {
        return res;
      }

      // k为合理值时，最大的n值不超过max_k，其值为最大的k个数的和
      int max_k = 45 - (9 - k) * (10 - k) / 2;
      if (n > max_k) {
        return res;
      }

      vector<int> path;
      vector<int> data;
      // 初始化待回溯的数据1-9
      for (int i = 0; i < 9; ++i) {
        data.push_back(i + 1);
      }
      inner(k, n, data, 0, path, res);
      
      return res;
    }
};
```