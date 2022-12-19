### 解题思路
这里直接采用DFS递归即可，每次递归时度返回对应节点的子二叉树的被修改后属性，
需要注意一点，如果本节点，左子树，右字树都是0时，一定要返回nullptr,而不是返回一个[0];

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
    
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        TreeNode* curNode = new TreeNode(root->val);

        if (dfs(root->left) != nullptr) {
            curNode->left = dfs(root->left);
        } 
        if(dfs(root->right) != nullptr) {
            curNode->right = dfs(root->right);
        } 

        if( curNode->val ==0 && curNode->left == nullptr && curNode->right == nullptr) {
            return nullptr;
        } else {
            return curNode;
        }

        
    }
};
```