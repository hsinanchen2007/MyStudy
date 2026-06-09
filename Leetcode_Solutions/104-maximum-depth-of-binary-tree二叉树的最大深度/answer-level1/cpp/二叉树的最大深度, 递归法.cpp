### 解题思路
此处撰写解题思路
1. 当树是空树，返回0
2. 深度优先搜索，当结点是叶子结点时，返回当前深度；当结点是非叶子结点时，返回左子树的深度值和右子树的深度值的较大值
3. 每向下递归一次，深度+1

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;


        return DFS(root, 1);
    }

    int DFS(TreeNode* node, int&& depth) {
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        
        int left =0;
        if (node->left != nullptr)
            left = DFS(node->left, depth+1);

        int right = 0;
        if (node->right != nullptr)
            right = DFS(node->right, depth+1);

        return max(left, right);
    }
};
```