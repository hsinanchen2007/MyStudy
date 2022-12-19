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
class Solution 
{
public:
    vector<int> v;

    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root)
        {
            v.push_back(root->val);
            if(root->left) preorderTraversal(root->left);     //判断后遍历
            if(root->right) preorderTraversal(root->right);   //判断后遍历
        }

        return v;
    }
};
```