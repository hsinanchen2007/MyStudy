### 解题思路
定义一个函数leafNode，输入是根节点和数组，作用是将树的叶子节点保存到数组中。
将两个根节点root1,root2都传入leafNode函数中，得到两个存储叶子结点的数组，然后比较两个数组是否相等。

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
    void leafNode(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)  return ;
        if(root->left==NULL && root->right==NULL)   
            res.push_back(root->val);
        leafNode(root->left,res);
        leafNode(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        leafNode(root1,res1);
        leafNode(root2,res2);

        return res1==res2;
    }
};
```