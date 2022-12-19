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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return {};
        TreeNode* last=root;
        TreeNode* nlast=NULL;
        vector<int> res1;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* x=Q.front();
            Q.pop();
            res1.push_back(x->val);
           

            if(x->left!=NULL)
            {
                Q.push(x->left);
                nlast=x->left;
            }
            if(x->right!=NULL)
            {
                Q.push(x->right);
                nlast=x->right;
            }
            if(x==last)
            {
                 res.push_back(res1);
                res1.clear();
                last=nlast;
            }
            
        }
        return res;
    }
};
```