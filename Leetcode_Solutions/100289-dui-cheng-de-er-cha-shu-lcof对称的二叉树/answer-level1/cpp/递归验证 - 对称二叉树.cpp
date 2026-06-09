### 解题思路
- 对左子树进行**根-左-右**顺序遍历，生成字符串`left_str`,对左子树进行**根-右-左**遍历，生成字符串`right_str`。
- 若`left_str`与`right_str`相等，则对称，否则不对称



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

    void dfs_NLR(TreeNode *root, string& ans){
        if(root){
            ans += to_string(root->val);
            dfs_NLR(root->left, ans);
            dfs_NLR(root->right, ans);
        }
        else{
            ans += "0";
            return;
        }
    }

    void dfs_NRL(TreeNode *root, string& ans){
        if(root){
            ans += to_string(root->val);
            dfs_NRL(root->right, ans);
            dfs_NRL(root->left, ans);
        }
        else{
            ans += "0";
            return;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        string left_str = "";
        string right_str = "";
        if(root->left == NULL && root->right == NULL) return true;
        dfs_NLR(root->left, left_str);
        dfs_NRL(root->right, right_str);
        if(left_str == right_str) return true;
        return false;
    }
};
```