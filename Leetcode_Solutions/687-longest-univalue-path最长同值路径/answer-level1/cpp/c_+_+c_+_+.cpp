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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    //返回以当前节点为根节点的的直线子路径（也就是不交叉路径）的最大同值路径
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(root->left && root->val == root->left->val) 
            l += 1;
        else l = 0;
        if(root->right && root->val == root->right->val)
            r += 1;
        else r = 0;
        ans = max(ans, r + l);
        return max(l, r);
    }
};
```