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
    bool dfs(TreeNode* node, long long minv, long long maxv)
    {
        if(!node)
            return true;
        if(node->val>maxv || node->val<minv)
            return false;
        return dfs(node->left,minv,node->val-(long long)1)&&dfs(node->right,node->val+(long long)1,maxv);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return dfs(root, INT_MIN, INT_MAX);
    }
};
```