### 解题思路
ans：存储当前阶段最大联通节点数，ans-1 为最当前阶段最大直径
leftDepth + rightDepth + 1: 当前节点的最大路径长度（即，当前阶段的ans），即左右子树的最大深度再加该节点，随时更新ans，
max(leftDepth, rightDepth) + 1： 当前节点最大深度（即，通过的节点数，包含该节点）
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        depth(root);
        return ans - 1;
    }
    int depth(TreeNode* root){
        if(!root)   return 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        ans = ans < (leftDepth + rightDepth + 1) ? leftDepth + rightDepth + 1 : ans;

        return max(leftDepth, rightDepth) + 1;
    }













};
```