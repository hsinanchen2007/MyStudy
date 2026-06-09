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
    int ans;
    int getH(TreeNode* root){
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        int l=getH(root->left);
        int r=getH(root->right);
        ans=max(ans,l+r);
        return max(l,r)+1;
    }
  
    int diameterOfBinaryTree(TreeNode* root) {
        getH(root);
        return ans;
    
    }
};
```