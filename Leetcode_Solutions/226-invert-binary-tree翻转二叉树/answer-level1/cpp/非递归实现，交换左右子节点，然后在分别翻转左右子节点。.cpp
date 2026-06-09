### 解题思路
此处撰写解题思路

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        std::queue<TreeNode*> queue;
        TreeNode *node = root;
        queue.push(node);
        while(queue.size())
        {
            node = queue.front();
            queue.pop();
            std::swap(node->left, node->right);
            if(node->left != NULL)
                queue.push(node->left);
            if(node->right != NULL)
                queue.push(node->right);
        }

        return root;
    }
};
```