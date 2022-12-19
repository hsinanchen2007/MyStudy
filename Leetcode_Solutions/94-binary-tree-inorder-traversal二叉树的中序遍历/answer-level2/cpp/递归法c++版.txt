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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;      
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL){
            inorder(root->left);
        }
        ans.push_back(root->val);
        if(root->right!=NULL){
            inorder(root->right);
        }
    }
};
```