### 解题思路
深度优先遍历，判断条件为是不是左子树。

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
    int sum = 0;
    void dfs(TreeNode* node) {
        if (!node)
            return;
        if (node->left)
            if(node->left->left == NULL && node->left->right == NULL)
                sum += node->left->val;  // 判断是不是左子节点
            dfs(node->left);
        if (node->right)
            dfs(node->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }
};

```

![image.png](https://pic.leetcode-cn.com/4a8e5a4fe7b0e40bf987ce7c0c432aee79e8e329964067d94c0ba354a3fecbd9-image.png)
