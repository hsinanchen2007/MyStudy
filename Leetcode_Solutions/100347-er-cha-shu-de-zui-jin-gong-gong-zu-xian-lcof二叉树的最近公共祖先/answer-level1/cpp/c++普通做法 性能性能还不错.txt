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
    TreeNode* t;
    int a;
    int b;
    int cnt=2;
    bool judge(TreeNode*root)
    {
        if(t)return false;
        if(!root)return false;
        if(root->val==a||root->val==b)
        {
            if(judge(root->left)||judge(root->right))
                if(t==NULL)
                    t=root;
            
            return true;
        }
        else if(judge(root->left)&&judge(root->right))
        {
            if(t==NULL)
                t=root;
            return true;
        }
        else if(judge(root->left)||judge(root->right))
            return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a=p->val;
        b=q->val;
        if(judge(root))
            return t;
        else return t;
    }
};
```