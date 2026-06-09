### 解题思路
对树进行中序遍历，并用n进行计算，如果n == k了，则即为所找值

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        int res;
        dfs(root, k, n, res);
        return res;
    }

    void dfs(TreeNode* root, int k, int& n, int &res) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, k, n, res);
        n++;
        if (n == k) {
            res = root->val;
        }
        dfs(root->right, k, n, res);
    }
};
```

欢迎关注微信公众号'码农黑板报'，一起学习交流