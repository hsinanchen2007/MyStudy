### 解题思路
深度优先搜索
![image.png](https://pic.leetcode-cn.com/34bc5b4df74f9d5d04f56fb824d575dcd471cb19280bd0b6668afe613d26fec6-image.png)


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
    vector<int> largestValues(TreeNode* root) {
        int h = height(root);
        vector<int> res(h, INT_MIN);
        dfs(res, 0, root);
        return res;
    }

    void dfs(vector<int>& res, int level, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        res[level] = std::max(res[level], node->val);
        dfs(res, level+1, node->left);
        dfs(res, level+1, node->right);
    }

    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return std::max(height(node->left), height(node->right)) + 1;
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/9e1b8e5edc9529c3730048cd3da4dece712969597ddd4c0b9cb67b11a4452c5a-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
