![image.png](https://pic.leetcode-cn.com/88a9807895fd9f6a2de2de74610ae680bfa2528762c2cca8dd27dc127ab4d499-image.png)

思路：
记录深度，根据深度把根节点放进去，然后递归左右节点，且深度加一。
这样得到的跟题目要求是反过来的，直接reverse即可。


```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        dfs(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(vector<vector<int>>& record, TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        if (record.size() <= depth) {
            record.emplace_back(vector<int>{node->val});
        } else {
            record[depth].emplace_back(node->val);
        }

        dfs(record, node->left, depth + 1);
        dfs(record, node->right, depth + 1);
    }
};
```
