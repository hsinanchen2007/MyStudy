### 解题思路

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
    int total=0;

    int sumNumbers(TreeNode* root) 
    {
        if(!root) return 0;
        DFS(root,"");
        return total;
    }

    void DFS(TreeNode* root,string num)
    {
        num+=to_string(root->val);
        if(root->left) DFS(root->left,num);
        if(root->right) DFS(root->right,num);
        if(!root->left && !root->right) total+=atoi(num.c_str());
    }
};
```