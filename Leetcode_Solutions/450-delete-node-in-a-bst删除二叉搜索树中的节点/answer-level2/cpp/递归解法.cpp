### 解题思路
从删除的三种情况去考虑

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            //情况一和情况二
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;
            //情况三
            TreeNode* RminNode=FindMin(root->right);
            root->val=RminNode->val;
            root->right=deleteNode(root->right,RminNode->val);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        return root;
    }

    TreeNode* FindMin(TreeNode* root){
        if(root->left) return FindMin(root->left);
        else return root;
    }
};
```