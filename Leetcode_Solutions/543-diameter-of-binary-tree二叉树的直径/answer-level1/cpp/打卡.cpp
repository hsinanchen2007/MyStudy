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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL ||(root->left == NULL && root->right == NULL)) return 0;
        int len = 0;
        int left = dfs(root->left, len);
        int right = dfs(root->right, len);
        if (left + right > len) len = left + right;
        return len;
    }
    int dfs(TreeNode* root, int &len) {
        if(root == NULL ) return 0;
        int left = dfs(root->left,len);
        int right = dfs(root->right,len);
        if(left + right > len) len = left + right;
        return left > right ? left + 1: right + 1;
    }
};
```