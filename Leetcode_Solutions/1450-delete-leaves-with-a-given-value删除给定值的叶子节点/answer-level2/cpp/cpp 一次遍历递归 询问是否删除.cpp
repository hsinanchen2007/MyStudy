

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (needdelete(root,target)) root=NULL;
        return root;
    }
    bool needdelete(TreeNode* temp,int target){
        if (temp->left!=NULL){
            if (needdelete(temp->left,target)) temp->left=NULL;
        }
        if (temp->right!=NULL){
            if (needdelete(temp->right,target)) temp->right=NULL;
        }
        if (temp->left==NULL and temp->right==NULL){
            if (temp->val==target) return true;
        }
        return false;
    }
};
```