### 解题思路
回溯法：
假设对于level = 3时已经存在状态树，且其叶子节点就是对应的结果
那么level = 4时，对于leve = 3的每个结果子集，num[3]可以有加入和不加入集合两种选择，即形成leve = 4的状态树。
code style 可以再做优化

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :12.2 MB, 在所有 C++ 提交中击败了100.00%的用户

其他方法，dp

### 代码

```cpp
class Solution {
public:
    void inner(int n, int level, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
      if (n == level) {
        res.push_back(path);
        return;
      }

      path.push_back(nums[level]);
      inner(n, level + 1, nums, path, res);
      path.pop_back();
      inner(n, level + 1, nums, path, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> path;
      vector<vector<int>> res;

      inner(nums.size(), 0, nums, path, res);

      return res;
    }
};
```