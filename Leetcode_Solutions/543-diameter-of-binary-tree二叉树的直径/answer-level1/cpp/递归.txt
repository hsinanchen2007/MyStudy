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
    //求最大直径
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    //函数功能是求以root为根节点的最大边数（深度）
    int dfs(TreeNode* root){
        if(!root)return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        //ans更新最大直径
        ans = max(ans,left+right);
        return max(left+1,right+1);
    }
};
```