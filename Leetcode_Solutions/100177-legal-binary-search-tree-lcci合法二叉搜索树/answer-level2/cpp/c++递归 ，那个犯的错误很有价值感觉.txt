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
   bool isValidBST_(TreeNode *root,TreeNode *min,TreeNode *max)
    {   
        if(!root) return true;
        if(max!=NULL&&root->val>=max->val) return false; 
        if(min!=NULL&&root->val<=min->val) return false;
        return isValidBST_(root->left,min,root)&& isValidBST_(root->right,root,max);
    }
    
    bool isValidBST(TreeNode* root) {
               /* if(!root) return true;
                if(root->left&&root->val>root->left->val)
                        bool left=isValidBST(root->left);
                if(root->right&&root->val<root->right->val);
                        bool right=isValidBST(root->right);
                return left&&right;// 这么写是错的 我们应该传进去一个最大最小。
                */
                //
      return isValidBST_(root,NULL,NULL);          
     }
};
```