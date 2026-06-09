### 解题思路

递推树的深度是2*n，总共的叶子节点是pow(2, 2*n)，幂集
剪枝条件：
1，左、右括号大于n
2，左括号数小于右括号数
3，添加左、右括号后，数量大于n

详见注释

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    // level表示树的深度，等于2n时，到达叶子节点
    // n表示括号的对数
    // left表示左括号的个数，right表示右括号个数
    // path用来回溯合法的叶子节点
    // ans记录合法的path
    void backtrack(int level, int n, int left, int right, string& path, vector<string>& ans) {
      // 到达叶子节点
      if (level == 2*n) {
        ans.push_back(path);
        return;
      }

      // 剪枝掉明显不合法的值
      if (left > n || right > n || left < right) {
        return;
      }

      char tmp[] = "()";
      for (int i = 0; i < 2; ++i) {
        // 假设当前状态合法，那么左括号添加后，个数不能大于n
        if (i == 0 && (left + 1 > n)) {
          continue;
        }

        if (i == 1 && (right + 1 > left)) {
          continue;
        }

        // 常规回溯
        path.push_back(tmp[i]);
        backtrack(level + 1, n, left + 1 - i, right + i, path, ans);
        path.pop_back();
      }
    }

    vector<string> generateParenthesis(int n) {
      string path;
      vector<string> ans;

      backtrack(0, n, 0, 0, path, ans);
      return ans;
    }
};
```