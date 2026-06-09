从 1 开始进行深搜，如果当前 path 的长度等于 k，判断当前的路径和是否等于 n (n == 0)，如果 k == 0 则将当前路径加入结果集。

在循环过程中，如果当前 i 大于 n，剪枝。

![image.png](https://pic.leetcode-cn.com/5999b81890d4d55537e47f304677aca7b7877a03940caa15f0dc45f5a542bbb1-image.png)


```
class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(1, k, n);
        return res;
    }

   private:
    void helper(int index, int k, int n) {
        if (path.size() == k) {
            if (n == 0) res.push_back(path);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (i > n) return; // 剪枝
            path.push_back(i);
            helper(i + 1, k, n - i);
            // 注意恢复状态
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> res;
};

```
