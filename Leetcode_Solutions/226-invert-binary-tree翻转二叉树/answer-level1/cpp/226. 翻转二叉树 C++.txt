### 解题思路
1.使用队列层序遍历二叉树，一边遍历一边反转二叉树的子树。
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
        if(root == NULL) return NULL;
        queue<TreeNode*> q_node;
        q_node.push(root);
        while(!q_node.empty()){
            TreeNode* current = q_node.front();
            q_node.pop();
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if(current->left != NULL){
                q_node.push(current->left);
            }
            if(current->right != NULL){
                q_node.push(current->right);
            }
        }
        return root;
    }
};
```