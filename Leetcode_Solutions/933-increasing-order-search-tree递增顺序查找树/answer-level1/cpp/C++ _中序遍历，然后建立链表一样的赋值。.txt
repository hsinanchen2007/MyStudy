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
    void inOrder(TreeNode*node,vector<int>&res)
    {
        if(node==NULL) return;
        inOrder(node->left,res);
        res.push_back(node->val);
        inOrder(node->right,res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inOrder(root,res);
        TreeNode* head=new TreeNode(0);
        TreeNode* ans=head;
        for(int v:res)
        {
            ans->right=new TreeNode(v);
            ans=ans->right;
        }
        return head->right;
    }
};
```