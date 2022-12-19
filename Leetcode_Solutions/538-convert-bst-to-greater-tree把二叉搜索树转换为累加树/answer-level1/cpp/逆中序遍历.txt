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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        if(!root)return NULL;
        inorder(root,sum);
        return root;
    }
    void inorder(TreeNode* &root,int &sum){
        if(root->right)
            inorder(root->right,sum);
        sum+=root->val;
        root->val=sum;
        if(root->left)
            inorder(root->left,sum);
    }
};
```