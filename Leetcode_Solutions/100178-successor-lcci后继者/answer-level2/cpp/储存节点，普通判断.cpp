
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
class Solution 
{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        vector<TreeNode*> help;//储存节点

        inorder(root,help);//中序遍历

        if(help.size()<=1) return NULL;

        int n=help.size();
        for(int i=0;i<n-1;i++)
            if(help[i]==p) return help[i+1];

        return NULL;

    }

    void inorder(TreeNode* root,vector<TreeNode*>& help)
    {
        if(root==NULL) return;
        inorder(root->left,help);
        help.push_back(root);
        inorder(root->right,help);
    }
};
```