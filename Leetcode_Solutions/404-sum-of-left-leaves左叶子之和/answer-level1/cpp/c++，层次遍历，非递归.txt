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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int sum=0;
        if(root==NULL)
            return 0;
        while(!Q.empty())
        {
            TreeNode* x=Q.front();Q.pop();
            //visit(x->val);
            if(x->left!=NULL)
            {
            if(x->left->left==NULL&&x->left->right==NULL)//左叶子节点肯定是从左子树产生的，所以左子节点都是在这个分支产生的。
            {
                sum+=x->left->val;
            }
                Q.push(x->left);
            }
            if(x->right!=NULL)
                Q.push(x->right);
        }
        return sum;
    }
   
};
```