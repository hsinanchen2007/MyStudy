### 思路
1. 对树使用前缀和
2. 使用 `unordered_map` 对树进行 [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)
3. 对 `unordered_map` 回溯

### 答题
```C++ []
class Solution {
public:
    void dfs(TreeNode* root, int ps, int sum, unordered_map<int, int>& vi, int& ans)
    {
        if (root == nullptr) return;
        root->val += ps;
        ans += vi[root->val - sum];
        vi[root->val]++;
        dfs(root->left, root->val, sum, vi, ans);
        dfs(root->right, root->val, sum, vi, ans);
        vi[root->val]--;
    }

    int pathSum(TreeNode* root, int sum) 
    {
        int ans = 0;
        unordered_map<int, int> vi;
        vi[0] = 1;
        dfs(root, 0, sum, vi, ans);
        return ans;
    }
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

