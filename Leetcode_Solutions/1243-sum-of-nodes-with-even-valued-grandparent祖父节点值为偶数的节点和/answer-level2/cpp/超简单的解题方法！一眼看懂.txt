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
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        intermediary(root,sum);
        return sum;
    }

    void intermediary(TreeNode* root,int& sum)
    {
        if(root->val%2==0)
        {
            if(root->left!=NULL)
            {
                if(root->left->left!=NULL)
                sum+=root->left->left->val;
                if(root->left->right!=NULL)
                sum+=root->left->right->val;
            }
            if(root->right!=NULL)
             {
                if(root->right->left!=NULL)
                sum+=root->right->left->val;
                if(root->right->right!=NULL)
                sum+=root->right->right->val;
            }
        }

        if(root->left!=NULL)
        intermediary(root->left,sum);
        if(root->right!=NULL)
        intermediary(root->right,sum); 
    }
};
