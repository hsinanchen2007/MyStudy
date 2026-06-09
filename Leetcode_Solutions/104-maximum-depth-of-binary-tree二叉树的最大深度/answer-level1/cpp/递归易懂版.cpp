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
    int maxDepth(TreeNode* root) {
        int t1,t2;
        if(root==NULL)return 0;
        t1=1+maxDepth(root->left);
        t2=1+maxDepth(root->right);
        return t1>t2?t1:t2;
    }
};
```