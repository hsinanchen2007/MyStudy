### 解题思路
代码写的比较冗长，但是窃以为思路比较清晰，分类讨论+dfs

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
    bool dfs(TreeNode* root,int sum,int temp){
        if(root!=NULL)
            if(root->left==NULL&&root->right==NULL)
                if(temp+root->val==sum) 
                    return true;
                else
                    return false;
            else
                if(root->left!=NULL&&root->right!=NULL)
                    if(dfs(root->left,sum,temp+root->val)==true)
                        return true;
                    else
                        return dfs(root->right,sum,temp+root->val);
                else{
                    if(root->left!=NULL)
                        return dfs(root->left,sum,temp+root->val);
                    if(root->right!=NULL)
                        return dfs(root->right,sum,temp+root->val);
                }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root,sum,0);
    }
};
```