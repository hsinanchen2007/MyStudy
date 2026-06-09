课上老师带我们手撸代码，根据根左右的顺序进行，分享给各位大神

```
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
    vector<int> res;
    vector<int> preorderTraversal(struct TreeNode* root) {
    if(root == NULL)
    {
         return res;
    }
    //根  
    res.push_back(root->val);
    //左
    if(root->left != NULL)
    {
        preorderTraversal(root->left);
    }
    //右
    if(root->right != NULL)
    {
        preorderTraversal(root->right);
    }
    
    return res;
    }
    
};
```
